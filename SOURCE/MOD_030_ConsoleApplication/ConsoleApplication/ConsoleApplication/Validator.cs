using Aml.Engine.CAEX;
using Aml.Engine.Services;
using System;

namespace ConsoleApplication
{
    public class Validator
    {

        public int LogLevel { get; set; }

        private ConsoleColor default_foreground { get; set; }

        public Validator(int logLevel)
        {
            // ToDo: Decide if setting LogLevel per Function call or per Property
            this.LogLevel = logLevel;

            //save default foreground color
            this.default_foreground = Console.ForegroundColor;
        }



        public void validate(CAEXDocument doc, string path)
        {
            // start validating aml

            ValidatorService service = ValidatorService.Register();

            var enumerator = service.ValidateAll(doc).GetEnumerator();
            bool FileChanged = false;

            while (enumerator.MoveNext())
            {
                // option for printing all options
                //printALLData_for_ValidationElement(enumerator.Current);
                
                // print Error
                print_Error(enumerator.Current);

                // ToDo: Implement Option to automatically repair all
                // try reparing
                if (Console.ReadLine().ToUpper().Trim()=="YES")
                {
                    //start reparing
                    FileChanged = true;
                    service.Repair(enumerator.Current);
                    PrintHelper.println($"Repair results:  {enumerator.Current.RepairResult}", ConsoleColor.Cyan);

                }
            }

            // no Errors in mistake
            if (enumerator.Current == null)
            {
                PrintHelper.println("No errors found", ConsoleColor.Green);
            }
            else if (FileChanged)
            {
                
                PrintHelper.println("Override file (yes/no) ?", this.default_foreground);

                // if override file
                if (Console.ReadLine().ToUpper().Trim() == "YES")
                {
                    doc.SaveToFile(path, true);

                    PrintHelper.println($"saved to file {path}", ConsoleColor.Cyan);
                }
                else
                {
                    // save to new file
                    Console.WriteLine("Please insert the Path for the File you want to save:");
                    string new_path = PrintHelper.GetDirectory();
                    // Only when User entered a valid Path
                    if (!String.IsNullOrEmpty(new_path))
                    {
                        doc.SaveToFile(new_path, true);
                        PrintHelper.println($"saved to file {new_path}", ConsoleColor.Cyan);
                    }
                }
            }
            ValidatorService.UnRegister();
            PrintHelper.Exit("Returning to Main Menu");

        }

        private void print_Error(ValidationElement validationElement)
        {
            PrintHelper.println("Found Error", ConsoleColor.Red);

            if (!String.IsNullOrEmpty(validationElement.LongDescription))
            {
                PrintHelper.println($"{validationElement.LongDescription}", ConsoleColor.Yellow);
            }
            else
            {
                PrintHelper.println($"Exception: {validationElement.ValidationInformation}", this.default_foreground);
            }

            PrintHelper.println($"Error with attribute \"{validationElement.ValidatedAttribute}\" ", this.default_foreground);

            PrintHelper.println($"Options for reparing \"{validationElement.AvailableRepairOptions}\" \n", ConsoleColor.Green);

            PrintHelper.println("Error in element:", this.default_foreground);
            PrintHelper.println($"{PrintHelper.line()} \n{validationElement.Element}\n{PrintHelper.line()} \n", ConsoleColor.Blue);

            PrintHelper.println("\nType yes for repairing option", ConsoleColor.Yellow);
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
