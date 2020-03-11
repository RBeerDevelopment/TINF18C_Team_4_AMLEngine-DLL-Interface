using Aml.Engine.CAEX;
using Aml.Engine.Services;
using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication
{
    public class Validator
    {

        public int LogLevel { get; set; }

        private ConsoleColor default_foreground { get; set; }

        public Validator(int logLevel)
        {
            this.LogLevel = logLevel;

            //save default foreground color
            this.default_foreground = Console.ForegroundColor;
        }



        public void validate(CAEXDocument doc, string path)
        {
            // start validating aml

            ValidatorService service = ValidatorService.Register();

            var validationResult = service.ValidateAll(doc);

            var enumerator = validationResult.GetEnumerator();

            while (enumerator.MoveNext())
            {
                // option for printing all options
                //printALLData_for_ValidationElement(enumerator.Current);
                
                // print Error
                this.print_Error(enumerator.Current);

                // try reparing
                if (Console.ReadLine().ToUpper().Contains("YES"))
                {
                    //start reparing
                    service.Repair(enumerator.Current);
                    println($"Repair results:  {enumerator.Current.RepairResult}", ConsoleColor.Cyan);

                }
            }

            // no Errors in mistake
            if (enumerator.Current == null)
            {
                println("No errors found", ConsoleColor.Green);
            }
            else
            {
                
                println("Override file (yes/no) ?", this.default_foreground);

                // if override file
                if (Console.ReadLine().ToUpper().Contains("YES"))
                {
                    doc.SaveToFile(path, true);

                    println($"saved to file {path}", ConsoleColor.Cyan);
                }
                else
                {
                    // save to new file
                    Console.WriteLine("Please insert the Path for the File you want to save:");
                    string new_path = @Console.ReadLine();
                    doc.SaveToFile(new_path, true);
                    println($"saved to file {new_path}", ConsoleColor.Cyan);
                }



            }
            // wait 3 seconds
            System.Threading.Thread.Sleep(3000);
            ValidatorService.UnRegister();

        }


        private void print_Error(ValidationElement validationElement)
        {
            println("ERROR", ConsoleColor.Red);

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

            println("\nType yes for repairing option", ConsoleColor.Yellow);
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
