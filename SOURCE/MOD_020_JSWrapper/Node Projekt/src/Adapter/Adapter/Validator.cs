using Aml.Engine.CAEX;
using Aml.Engine.Services;
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Adapter
{
    public class Validator
    {

        private ConsoleColor default_foreground { get; set; }

        public Validator()
        {
            // ToDo: Decide if setting LogLevel per Function call or per Property
            //save default foreground color
            this.default_foreground = Console.ForegroundColor;
        }



        public string validate(CAEXDocument doc, string path)
        {
            // start validating aml

            string validation_result = "";

            ValidatorService service = ValidatorService.Register();

            var enumerator = service.ValidateAll(doc).GetEnumerator();
            while (enumerator.MoveNext())
            {
                validation_result += print_Error(enumerator.Current) + "//";

            }

            ValidatorService.UnRegister();
            // no Errors in mistake
            if (enumerator.Current == null)
            {

                println("No errors found", ConsoleColor.Green);
                return "No errors found";
            }

            return validation_result;

        }

        public string validate_and_repair(CAEXDocument doc, string path)
        {
            // start validating aml
            string validation_result = "";

            ValidatorService service = ValidatorService.Register();

            var enumerator = service.ValidateAll(doc).GetEnumerator();
            bool FileChanged = false;

            while (enumerator.MoveNext())
            {
                // option for printing all options
                //printALLData_for_ValidationElement(enumerator.Current);

                // print Error
                validation_result += print_Error(enumerator.Current);
                println("\nType yes for repairing option", ConsoleColor.Yellow);

                // ToDo: Implement Option to automatically repair all
                // try reparing
                if (Console.ReadLine().ToUpper().Trim() == "YES")
                {
                    //start reparing
                    FileChanged = true;
                    service.Repair(enumerator.Current);
                    println($"Repair results:  {enumerator.Current.RepairResult}", ConsoleColor.Cyan);

                    validation_result += $"|{enumerator.Current.RepairResult}";
                }
                validation_result += "//";
            }

            // no Errors in mistake
            if (enumerator.Current == null)
            {
                println("No errors found", ConsoleColor.Green);
                return "No errors found";
            }
            else if (FileChanged)
            {

                doc.SaveToFile(path, true);
                println($"saved to file {path}", ConsoleColor.Cyan);

            }
            ValidatorService.UnRegister();

            return validation_result;
        }


        private string print_Error(ValidationElement validationElement)
        {
            println("Found Error", ConsoleColor.Red);

            if (!String.IsNullOrEmpty(validationElement.LongDescription))
            {
                println($"{validationElement.LongDescription}", ConsoleColor.Yellow);
            }
            else
            {
                println($"Exception: {validationElement.ValidationInformation}", this.default_foreground);
            }

            println($"Error with attribute \"{validationElement.ValidatedAttribute}\" ", this.default_foreground);

            println($"Options for reparing \"{validationElement.AvailableRepairOptions}\" \n", ConsoleColor.Green);

            println("Error in element:", this.default_foreground);
            println($"{this.line()} \n{validationElement.Element}\n{this.line()} \n", ConsoleColor.Blue);


            return $"{validationElement.ValidationInformation}|{validationElement.ValidatedAttribute}|{validationElement.AvailableRepairOptions}|{validationElement.Element}";
        }



        private void Error(string message, int _logLevel)
        {
            /*
             writes Error to console ??
             */
        }


        private void println(string message, ConsoleColor color)
        {
            Console.ForegroundColor = color;

            Console.WriteLine(message);

            Console.ForegroundColor = this.default_foreground;
        }


        private string line()
        {
            var x = "";
            for (int i = 0; i < 50; i++)
            {
                x += "_";
            }


            return x;
        }


        private void printALLData_for_ValidationElement(ValidationElement validationElement)
        {
            Console.WriteLine("descrition " + validationElement.LongDescription);
            Console.WriteLine("Element " + validationElement.Element);
            Console.WriteLine("ValidatedAttribute " + validationElement.ValidatedAttribute);
            Console.WriteLine("ValidationType " + validationElement.ValidationType);
            Console.WriteLine("ValidationInformation " + validationElement.ValidationInformation);
            Console.WriteLine("RepairResult " + validationElement.RepairResult);
            Console.WriteLine("CAEXElement " + validationElement.CAEXElement);
            Console.WriteLine("AvailableRepairOptions " + validationElement.AvailableRepairOptions);
            Console.WriteLine("\n\n");

        }
    }
}
