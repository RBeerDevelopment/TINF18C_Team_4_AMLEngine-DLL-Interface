using Aml.Engine.CAEX;
using System;
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
            //string path = @"../../../../../example_files/AutomationMLCMIRoleClassLib.aml";
            //string path = @"../../../../../example_files/fehler.aml";
            string path = "";
            string outPath;
            CAEXObject doc;

            // Contstructor with loglevel
            Validator validator = new Validator(1);


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

                        if ( CDokument != null)
                            validator.validate(CDokument,path);
                        break;

                    case "COMPRESS":
                        AMLXCompress(true);
                        break;
                    case "DECOMPRESS":
                        AMLXCompress(false);
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

            PrintHelper.exit();

            // Wait for 3 Seconds before closing, so the User can see the message
            // TODO Konfiguration zur abschaltung hinzufügen (per Startparameter?)
            System.Threading.Thread.Sleep(3000);
        }

        private static void AMLXCompress(bool CompressType)
        {
            string src, target;
            PrintHelper.DeCompressor_Choosage(CompressType);

            Console.WriteLine("What is your Input?\n");
            src = CompressType ? PrintHelper.GetDirectory() : PrintHelper.GetFile("AMLX-File","*.AMLX");
            if (String.IsNullOrEmpty(src) || (CompressType ? false : Path.GetExtension(src).ToUpper() != ".AMLX"))
                return;

            Console.WriteLine("Where do you want to save the Output?\n");
            target = PrintHelper.GetDirectory();
            if (String.IsNullOrEmpty(target))
                return;

            if (CompressType)
                DeCompressor.Compress(src, target);
            else
                DeCompressor.DeCompress(src, target);
        }

        private static CAEXDocument LoadFile(ref string AMLFile)
        {
            if (String.IsNullOrEmpty(AMLFile))
            {
                // Ask for File
                Console.WriteLine("Which File do you want to load?");
                AMLFile = PrintHelper.GetFile("AML-File", "*.AML");
            }
            // look up input is actual file
            if (String.IsNullOrEmpty(AMLFile))
                return null;
            else
                return CAEXDocument.LoadFromFile(AMLFile);  

        }
    }
}
