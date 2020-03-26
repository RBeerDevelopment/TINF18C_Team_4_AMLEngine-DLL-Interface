using Aml.Engine.CAEX;
using Aml.Engine.Services;
using System;

namespace ConsoleApplication
{
    public class Validator
    {

        private ConsoleColor default_foreground { get; set; }

        public Validator()
        {
            //save default foreground color
            this.default_foreground = Console.ForegroundColor;
        }

        public void validate(CAEXDocument doc, string path, ref Options CurrentOptions)
        {
            // start validating aml
            try
            {
                ValidatorService service = ValidatorService.Register();

                var enumerator = service.ValidateAll(doc).GetEnumerator();
                bool FileChanged = false;

                while (enumerator.MoveNext())
                {
                    if (CurrentOptions.PrintAllVal)
                        printALLData_for_ValidationElement(enumerator.Current);

                    // print Error
                    print_Error(enumerator.Current);

                    if (!CurrentOptions.AutoRepair)
                        PrintHelper.println("\nType yes for repairing option", ConsoleColor.Yellow);

                    // try reparing
                    if (CurrentOptions.AutoRepair || Console.ReadLine().ToUpper().Trim() == "YES")
                    {
                        // start reparing
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
            }
            catch(Exception e)
            {
                Console.WriteLine("Exception: " + e.ToString());
                PrintHelper.println("Could Validate File", ConsoleColor.Red);
            }
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
        }

        private void printALLData_for_ValidationElement(ValidationElement validationElement)
        {
            PrintHelper.println("\n\n Information for Current Element: ", ConsoleColor.Green);
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
