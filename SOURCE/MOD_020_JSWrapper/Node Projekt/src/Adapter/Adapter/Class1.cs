using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Aml.Engine;
using Aml.Engine.CAEX;
using System.Data;
using System.Threading.Tasks;
using System;

namespace Adapter
{
    public class Class1
    {
    }

    public class Startup
    {
        public async Task<object> Invoke(dynamic payload)
        {
            /**
             * payload structure:
             *      payload.function_name   : function name to call, see switch for more
             *      
             *      payload.path            : path to caex document ?
             *      
             *      
             *output structure:
             *      output.result           : string -> the result of the action
             * 
             */


            /** 
             *                     
            * TODO: METHOD CHECK FOR ALL PARAMETERS NEEDED //ggf. Internal element hinzufügen, checken ob benötigt??? https://stackoverflow.com/questions/2839598/how-to-detect-if-a-property-exists-on-an-expandoobject
             * 
             * 
             * // TRAVERSING ??? -> no use case???
             * 
             */

            Console.WriteLine($"Calling function {payload.function_name}");
            Console.WriteLine($"Path to CAEX {payload.path}");


            //output to give back
            dynamic output = new object();

            // global caex document to work with
            CAEXDocument caex = CaexOpener.OpenCaexSafe(@payload.path);

            if (caex == null)
            {
                output.result = "Cannot open file, ERROR occured";
                Console.WriteLine("Stopping c# programm...");

                output.result = "Cannot open file, ERROR occured";
                return output;
            }


            switch ((payload.function_name as string).ToUpper())
            {
                case "CREATETESTFILE":
                    var caexDocument = CAEXDocument.New_CAEXDocument();
                    caexDocument.SaveToFile("build/Lucas_ist_ein_doofi.aml", true);
                    output.result = "Created test file in build/Lucas_ist_ein_doofi.aml";
                    break;


                case "INSTANCEHIERARCHY_APPEND":
                    var hierarchyInstanceName = payload.instance;

                    // only string or Array of Tupels (key,value)
                    var hierarchyInstance = caex.CAEXFile.InstanceHierarchy.Append(hierarchyInstanceName);



                    if (((IDictionary<String, object>)payload).ContainsKey("internalelement"))
                    {
                        hierarchyInstance.InternalElement.Append(payload.internalelement);
                    }

                    output.result = $"Created instance hierarchy {hierarchyInstanceName} on file";
                    break;

                case "INSTANCEHIERARCHY_GET":

                    // int oder string oder Tupel (Name:"Version", Value:"1.0") auf Internes Element von Instanz

                    var indexer = payload.indexer;

                    // WORKING ????
                    output.result = caex.CAEXFile.InstanceHierarchy[indexer];

                    break;


            
                    /*
                     * @Markus
                     * die Rückgabe ist ein String:
                     *          Aufbau:   Ein Fehler -> Infos getrennt durch "|" 
                     *                   Fehler sind getrennt durch "//"
                     *                   
                     *          => Zumindest so geplannt :D
                     *          **/
                case "VALIDATE":
                    var validator = new Validator();

                    output.result=validator.validate(caex, payload.path);
                    break;

                case "REPAIR":
                    validator = new Validator();

                    output.result = validator.validate_and_repair(caex, payload.path);
                    break;


                case "CREATE CLASS / SUBCLASS / InternalLinks usw.":
                    /*
                     * SystemUnitClassLib -> Application of instantiation of a SystemUnitClass to insert an InternalElement.
                     * InterfaceClassLib -> Creation of class to class relations using AutomationML Base Classes. 
                     * InternalLinks                                                                                
                     * SEARCHING / QUERYING IN DOCUMENT ????                                                                        MHM
                     * Transformation of an AML document to a higher version using the CAEXSchemaTransformer.                       NO
                     * 
                     * **/


                    output.result = "NOT IMPLEMENTED YET, MAYBE NEVER, WHO KNOWS";

                    break;

                default:
                    break;
            }


            caex.SaveToFile(@payload.path,true);

            return output;
        }
    }
}
