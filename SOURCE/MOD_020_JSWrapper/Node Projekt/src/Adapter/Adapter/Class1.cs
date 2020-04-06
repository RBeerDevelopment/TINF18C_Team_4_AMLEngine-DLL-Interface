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


            /** TODO
             *                     
             * // TRAVERSING ??? -> no use case???
             ** SystemUnitClassLib -> Application of instantiation of a SystemUnitClass to insert an InternalElement.
                     * InterfaceClassLib -> Creation of class to class relations using AutomationML Base Classes. 
                     * InternalLinks                                                                                
                     * SEARCHING / QUERYING IN DOCUMENT ????                                                                        MHM
                     * Transformation of an AML document to a higher version using the CAEXSchemaTransformer.                       NO
                     * 
             * 
             */
            if (!GlobalHelper.dynamicPayloadHasKeys(payload, new[] { "function_name", "path" }))
                return "function_name and path expected";

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
                    if (!GlobalHelper.dynamicPayloadHasKeys(payload, new[] { "instance", "path" }))
                        return "instance: name for the instance expected";

                    var hierarchyInstanceName = payload.instance;

                    // only string or Array of Tupels (key,value)
                    var hierarchyInstance = caex.CAEXFile.InstanceHierarchy.Append(hierarchyInstanceName);



                    if (!GlobalHelper.dynamicPayloadHasKeys(payload, "internalelement"))
                        hierarchyInstance.InternalElement.Append(payload.internalelement);


                    output.result = $"Created instance hierarchy {hierarchyInstanceName} on file";
                    break;

                case "INSTANCEHIERARCHY_GET":
                    if (!GlobalHelper.dynamicPayloadHasKeys(payload, "indexer"))
                        return "indexer expected: name for the indexer to return";
                    // int oder string oder Tupel (Name:"Version", Value:"1.0") auf Internes Element von Instanz

                    var indexer = payload.indexer;
                    var hierarchy = getInstanceHierarchy(indexer,caex);
                    // WORKING ???? maybe tostring
                    output.result = hierarchy;

                    break;

                // TODO: Test this case
                case "INSTANCEELEMENT_APPEND":
                    if (!GlobalHelper.dynamicPayloadHasKeys(payload, "indexer"))
                        {return "indexer expected: name for the indexer to return";}
                    else if(!GlobalHelper.dynamicPayloadHasKeys(payload, "inElement")) {
                        return "instance element expected: name for the new element to append";
                    }
                    indexer = payload.indexer;
                    hierarchy = getInstanceHierarchy(indexer,caex);
                    hierarchy.InternalElement.Append();
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

                    output.result = validator.validate(caex, payload.path);
                    break;

                case "REPAIR":
                    validator = new Validator();

                    output.result = validator.validate_and_repair(caex, payload.path);
                    break;


                case "CREATE CLASS / SUBCLASS / InternalLinks usw.":
                    output.result = "NOT IMPLEMENTED YET, MAYBE NEVER, WHO KNOWS";

                    break;

                default:
                    return $"Switch does not know about that the job {payload.function_name}";
                    
            }

            caex.SaveToFile(@payload.path, true);

            return output;
        }

        private InstanceHierarchyType getInstanceHierarchy(string indexer,CAEXDocument caex)
        {
            return caex.CAEXFile.InstanceHierarchy[indexer];
        }
    }
}
