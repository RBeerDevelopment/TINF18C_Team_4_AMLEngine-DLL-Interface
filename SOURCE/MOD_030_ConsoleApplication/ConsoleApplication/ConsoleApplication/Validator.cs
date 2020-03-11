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

            this.default_foreground = Console.ForegroundColor;
        }


        public bool validate(CAEXDocument doc)
        {
            /*
             * var validationResult_withoutString = service.ValidateAllWithoutStrictID(doc);

             Validate and log Errors with parsing here
             */
            ValidatorService service = ValidatorService.Register();

            var validationResult = service.ValidateAll(doc);

            var enumerator = validationResult.GetEnumerator();

            while (enumerator.MoveNext())
            {
                Console.ForegroundColor = ConsoleColor.Red;

                //printALLData_for_ValidationElement(enumerator.Current);
                Console.WriteLine(this.createMessage(enumerator.Current));

                Console.ForegroundColor = this.default_foreground;
            }

            ValidatorService.UnRegister();

            return true;
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

        private string createMessage(ValidationElement validationElement)
        {
            var message = "";

            if (!String.IsNullOrEmpty(validationElement.LongDescription))
            {
                message += $"{validationElement.LongDescription} \n";
            }
            else
            {
                message += $"Exception: {validationElement.ValidationInformation} \n";
            }

            message += $"Error with attribute \"{validationElement.ValidatedAttribute}\" \n";

            message += $"Options for reparing \"{validationElement.AvailableRepairOptions}\" \n";

            message += $" \nError in element:\n{this.line()} \n{validationElement.Element}\n{this.line()} \n";


            return message;
        }



        private void Error(string message, int _logLevel)
        {
            /*
             writes Error to console ??
             */
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
    }
}
