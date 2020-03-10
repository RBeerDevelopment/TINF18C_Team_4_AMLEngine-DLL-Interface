using Aml.Engine.CAEX;
using System;

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
    class Program
    {


        static void Main(string[] args)
        {
            string path = "C:/DHBW/Theorie/Semester 3/SWE/src/BeispielDateien/Rumpf1.aml";
            string outPath;
            CAEXObject doc;


            // Contstructor with loglevel
            Validator validator = new Validator(1);
            DeCompressor deCompressor = new DeCompressor();


            PrintHelper.welcome();

            bool loop = true;

            while (loop)
            {
                PrintHelper.loopExplanation();


                // TODO: Improve choose options
                switch (Console.ReadLine())
                {
                    case "1":
                        //validate file

                        validator.validate(LoadFile(path));
                        break;

                    case "2":
                        //  DE / Compressor

                        PrintHelper.DeCompressor_Choosage();

                        var src = Console.ReadLine();
                        var target = Console.ReadLine();

                        switch (Console.ReadLine())
                        {
                            case "1":
                                // Compress
                                deCompressor.Compress(src, target);
                                break;
                            case "2":
                                //decompress
                                deCompressor.DeCompress(src, target);
                                break;

                            default:
                                Console.WriteLine("Error, no case found");
                                break;
                        }

                        break;
                    case "3":
                        loop = false;
                        break;


                    default:
                        Console.WriteLine("Cannot Use Input \n");
                        continue;
                }

            }

            PrintHelper.exit();


            // 
            throw new NotImplementedException("@joshua sleep");
        }

        public static CAEXDocument LoadFile(string path)
        {
            /*
             Loads file
             */
            Console.WriteLine("give me path to file: ");
            //read file
            // look up input is actual file
            // load file
            
            return CAEXDocument.LoadFromFile(path);  

            throw new NotImplementedException("DO IT");

            return null;
        }
    }
}
