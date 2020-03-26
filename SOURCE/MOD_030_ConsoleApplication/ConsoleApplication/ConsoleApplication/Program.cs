using Aml.Engine.CAEX;
using System;
using System.Collections.Generic;
using System.IO;

/**
 * Ablauf Diagramme:
 * https://raw.githubusercontent.com/RBeerDevelopment/TINF18C_Team_4_AMLEngine-DLL-Interface/master/PROJECT/Pictures/Diagrams/aktivitaetsdiagrammValidation.png
 * https://raw.githubusercontent.com/RBeerDevelopment/TINF18C_Team_4_AMLEngine-DLL-Interface/master/PROJECT/Pictures/Diagrams/aktivitaetsdiagrammPacking.png
 *
 * Dokument:
 * https://github.com/RBeerDevelopment/TINF18C_Team_4_AMLEngine-DLL-Interface/wiki/System-Requirements

 * Willkommen
 * SCHLEIFE: 
 *      Entscheiden zwischen 
 *           1. File-Validation und 
 *           2. De / Compressor
 *           3. EXIT
 *           
 *          1. File Validation
 *              GIB Pfad zu Datei ein
 *              -> Ergebniss wird aus gegeben
 *          
 *          2. Entscheiden zwischen 
 *                  1. Packen und
 *                  2. Entpacken
 *              
 *                  1. Packen:
 *                      gib Dateipfad ein zu AMl Datei
 *                      gib Verzeichnisspfad ein / für Speicherort
 *                  
 *                  2. Entpacken
 *                      gib Dateipfad ein zu AMLX (zip) Datei
 *                      gib Verzeichnisspfad ein / für Speicherort
 *                      
 *          3. EXIT
 *              durchbricht Loop
 */

namespace ConsoleApplication
{
    public class Program
    {
        [STAThread]
        public static void Main(string[] args)
        {
            try
            {
                string path = "";
                Options CurrentOptions = new Options();

                Validator ValidatorInstance = new Validator();
                PrintHelper.welcome();

                bool loop = true;

                while (loop)
                {
                    PrintHelper.loopExplanation();


                    // TODO: Improve choose options
                    switch (Console.ReadLine().ToUpper())
                    {
                        case "VALIDATE":
                            //validate file
                            CAEXDocument CDokument = LoadFile(ref path);
                            Console.WriteLine(path);
                            if (CDokument != null)
                                ValidatorInstance.validate(CDokument, path, ref CurrentOptions);
                            break;

                        case "COMPRESS":
                            AMLXCompress();
                            break;
                        case "DECOMPRESS":
                            AMLXDeCompress();
                            break;
                        case "OPTIONS":
                            EditOptions(ref CurrentOptions);
                            break;
                        case "EXIT":
                        case "QUIT":
                            loop = false;
                            break;


                        default:
                            Console.WriteLine("Invalid Input \n");
                            continue;
                    }

                }

                // Wait for 3 Seconds before closing, so the User can see the message
                // TODO Konfiguration zur abschaltung hinzufügen (per Startparameter?)
                PrintHelper.Exit("thanks for working with us, please donate under...");
            }
            catch(Exception e)
            {
                Console.WriteLine("Exception: " + e.ToString());
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine("SCHWERER AUSNAHMEFEHLER. PROGRAMM WIRD IN 20 SEKUNDEN BEENDET");
                System.Threading.Thread.Sleep(20000);
            }
        }

        private static void AMLXCompress()
        {
            string sourceAMLFile, target, newFile;
            bool AnotherFile;
            List<string> FilesToAdd = new List<string>();
            PrintHelper.DeCompressor_Choosage(true);

            Console.WriteLine("What is your Input AML-File?\n");
            sourceAMLFile = PrintHelper.GetFile("AML-File","*.AML");
            if (String.IsNullOrEmpty(sourceAMLFile))
                return;

            Console.WriteLine("Do you want to add another File?(Yes/No)");
            AnotherFile = Console.ReadLine().ToUpper() == "YES";
            while(AnotherFile)
            {
                newFile = PrintHelper.GetFile();
                if (!String.IsNullOrEmpty(newFile))
                {
                    FilesToAdd.Add(newFile);
                    Console.WriteLine("Do you want to add more Files?(Yes/No)");
                    AnotherFile = Console.ReadLine().ToUpper() == "YES";
                }
                else
                    break;
            }

            Console.WriteLine("Where do you want to save the Output?\n");
            target = PrintHelper.GetDirectory();
            if (String.IsNullOrEmpty(target))
                return;
            DeCompressor.Compress(sourceAMLFile, target, FilesToAdd);
        }

        private static void AMLXDeCompress()
        {
            string src, target;
            PrintHelper.DeCompressor_Choosage(false);

            Console.WriteLine("What is your Input?\n");
            src = PrintHelper.GetFile("AMLX-File", "*.AMLX");
            if (String.IsNullOrEmpty(src) || (Path.GetExtension(src).ToUpper() != ".AMLX"))
                return;

            Console.WriteLine("Where do you want to save the Output?\n");
            target = PrintHelper.GetDirectory();
            if (String.IsNullOrEmpty(target))
                return;
            DeCompressor.DeCompress(src, target);
        }

        private static CAEXDocument LoadFile(ref string AMLFile)
        {
            if (String.IsNullOrEmpty(AMLFile))
            {
                // Ask for File
                Console.WriteLine("Which File do you want to validate?");
                AMLFile = PrintHelper.GetFile("AML-File", "*.AML");
            }
            // look up input is actual file
            if (String.IsNullOrEmpty(AMLFile))
                return null;
            else
                return CAEXDocument.LoadFromFile(AMLFile);  

        }
        private static void EditOptions(ref Options CurrentOptions)
        {
            bool Continue = true;
            do
            {
                PrintHelper.printOptions();
                string SelectedOption = Console.ReadLine().ToUpper();
                switch (SelectedOption)
                {
                    case "":
                    case "EXIT":
                    case "QUIT":
                        Continue = false;
                        break;
                    case "AUTOREPAIR":
                        PrintHelper.printOptionAutoRepair(CurrentOptions.AutoRepair);
                        try
                        {
                            CurrentOptions.AutoRepair = bool.Parse(Console.ReadLine());
                        }
                        catch (Exception)
                        {
                            PrintHelper.println("Invalid Value. Did not Change Config", ConsoleColor.Red);
                        }
                        Console.WriteLine("Do you want to Edit another Value?");
                        if (Console.ReadLine().ToUpper() == "NO")
                            Continue = false;
                        break;
                    case "PRINTALLVAL":
                        PrintHelper.printOptionAutoRepair(CurrentOptions.PrintAllVal);
                        try
                        {
                            CurrentOptions.PrintAllVal = bool.Parse(Console.ReadLine());
                        }
                        catch (Exception)
                        {
                            PrintHelper.println("Invalid Value. Did not Change Config", ConsoleColor.Red);
                        }
                        Console.WriteLine("Do you want to Edit another Value?");
                        if (Console.ReadLine().ToUpper() == "NO")
                            Continue = false;
                        break;
                    default:
                        Console.WriteLine("This Option does not Exist.");
                        Console.WriteLine("Do you want to try again?");
                        if (Console.ReadLine().ToUpper() == "NO")
                            Continue = false;
                        break;
                }
            } while (Continue);
            Console.Clear();
            PrintHelper.Exit("Redirecting to Main Menu");
        }
    }
}
