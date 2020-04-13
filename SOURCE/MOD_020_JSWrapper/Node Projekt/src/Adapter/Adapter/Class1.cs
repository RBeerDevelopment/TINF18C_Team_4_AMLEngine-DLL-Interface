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
             *  * SystemUnitClassLib -> Rückgabe wert überprüfen / Verbessern   |=> Die frage ist, ob man die Hierarchie irgendwie zurück geben kann
                * InterfaceClassLib -> Rückgabe wert überprüfen / Verbessern    |=>
                * SEARCHING / QUERYING IN DOCUMENT ????  -> extra class                                                    Ja
                * change data in instance hierarchy | element = null löscht Element
             */

            Console.WriteLine("Testeroni"); // FIXME: Delete
            //Console.WriteLine($"This is the payload function_name: {payload.function_name}");
            if (!GlobalHelper.dynamicPayloadHasKeys(payload, new[] { "function_name", "path" }))
                throw new Exception("Error: function_name and path expected");

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
                throw new Exception("Error: Cannot open file");
            }

            Console.WriteLine(payload.function_name);
            switch ((payload.function_name as string).ToUpper())
            {
                case "INSTANCEHIERARCHY_APPEND":
                    if (!GlobalHelper.dynamicPayloadHasKeys(payload, new[] { "instance", "path" }))
                        throw new Exception("Error: name for the instance expected");

                    var hierarchyInstanceName = payload.instance;

                    // only string or Array of Tupels (key,value)
                    var hierarchyInstance = caex.CAEXFile.InstanceHierarchy.Append(hierarchyInstanceName);



                    if (!GlobalHelper.dynamicPayloadHasKeys(payload, "internalelement"))
                        hierarchyInstance.InternalElement.Append(payload.internalelement);


                    output.result = $"Created instance hierarchy {hierarchyInstanceName} on file";
                    break;

                case "INSTANCEHIERARCHY_GET":
                    if (!GlobalHelper.dynamicPayloadHasKeys(payload, "indexer"))
                        throw new Exception("Error: name for the indexer to return expected");
                    // int oder string oder Tupel (Name:"Version", Value:"1.0") auf Internes Element von Instanz

                    var indexer = payload.indexer;
                    var hierarchy = getInstanceHierarchy(indexer, caex);
                    // WORKING ???? maybe tostring
                    output.result = hierarchy;

                    break;


                /*
                 * Requried:           payload.unitclasslib_name
                 * 
                 * Optional:                payload.unitclass_name
                 *                          payload.indexer             => where to put the new class
                 * 
                 * **/
                case "CREATE_SYSTEMUNITCLASS":

                    if (GlobalHelper.dynamicPayloadHasKeys(payload, "unitclasslib_name"))
                    {
                        var lib_name = payload.unitclasslib_name;
                        var slib = caex.CAEXFile.SystemUnitClassLib.Append(lib_name);

                        if (GlobalHelper.dynamicPayloadHasKeys(payload, "unitclass_name"))
                        {
                            var class_name = payload.unitclass_name;
                            var uclass = slib.SystemUnitClass.Append(class_name);

                            if (GlobalHelper.dynamicPayloadHasKeys(payload, "indexer"))
                            {
                                indexer = payload.indexer;
                                hierarchy = getInstanceHierarchy(indexer, caex);

                                var new_hierarchy = hierarchy.Insert(uclass.CreateClassInstance());
                                output.result = $"Created UnitclassLib {lib_name}, created systemunitclass {class_name} and attached to hierarchy{indexer}";
                            }
                            else
                            {
                                output.result = $"Created UnitclassLib {lib_name} and created systemunitclass {class_name}";
                            }

                        }
                        else
                        {
                            output.result = $"Created UnitclassLib {lib_name}";
                        }
                    }
                    else
                    {
                        throw new Exception("Error: unitclasslib_name is missing");
                    }

                    break;


                /*
                 * Requried:           payload.interface_classname
                 *  
                 * Optional:            payload.iface_name
                 * **/
                case "CREATE_INTERFACECLASS":

                    if (GlobalHelper.dynamicPayloadHasKeys(payload, "interface_classname"))
                    {
                        var iface_classname = payload.interface_classname;
                        var iface_class = caex.CAEXFile.InterfaceClassLib.Append(iface_classname);

                        if (GlobalHelper.dynamicPayloadHasKeys(payload, "iface_name"))
                        {
                            var iface_name = payload.iface_name;
                            var iface = iface_class.InterfaceClass.Append(iface_name);

                            output.result = $"Created Interface-class {iface_classname} and Interface {iface_name}";
                        }
                        else
                        {
                            output.result = $"Created Interface-class {iface_classname}";
                        }
                    }
                    else
                    {
                        throw new Exception("Error: missing fields");
                    }

                    break;

                /*
                 * This case appends a new element to an existing index
                 * required parameters: payload.indexer, payload.inElement
                 */ 
                case "INSTANCEELEMENT_APPEND":
                    if (!GlobalHelper.dynamicPayloadHasKeys(payload, "indexer"))
                    { throw new Exception("Error: name for the indexer is missing"); }
                    else if (!GlobalHelper.dynamicPayloadHasKeys(payload, "inElement"))
                    {
                        throw new Exception("Error: instance element expected: name for the new element to append");
                    }
                    var instanceHierarchy = getInstanceHierarchy(payload.indexer, caex); //get instancehierarchy
                    var elementNew = payload.inElement;
                    instanceHierarchy.InternalElement.Append(elementNew); //add new element
                    output.result = $"Created new internal element named {payload.inElement}";
                    break;

                /*
                 * his case rewrited the contents of an element to the given data
                 */
                case "CHANGE_DATA":
                    if(!GlobalHelper.dynamicPayloadHasKeys(payload, "indexer")) {
                        throw new Exception("Error: name for indexer is missing");
                    } else if(!GlobalHelper.dynamicPayloadHasKeys(payload, "data")) {
                        throw new Exception("Error: no data found");
                    }
                    var indexer2 = payload.indexer;
                    var hierarchy2 = getInstanceHierarchy(indexer2, caex);
                    var dataToWrite2 = payload.data;
                    var dataOld2 = hierarchy2.InternalElement;
                    hierarchy2.InternalElement = dataToWrite2;
                    if(dataOld2 != null) {
                        output.result = $"Changed data from {dataOld2} to {dataToWrite2}.";   
                    } else {
                        output.result = $"Changed cell data to {dataToWrite2}";
                    }
                    break;
                case "SEARCH_AND_CHANGE_CONTENT":
                    if(!GlobalHelper.dynamicPayloadHasKeys(payload, "searchWord")) {
                        throw new Exception("Error: searchWord field was not found");
                    } else if(!GlobalHelper.dynamicPayloadHasKeys(payload, "data")) {
                        throw new Exception("Error: data field was not found");
                    }
                    var searchWord = payload.searchWord;
                    var dataToWrite3 = payload.data;
                    var hierarchyIndex = searchForElement(searchWord, caex); // search for keyword
                    if(hierarchyIndex == null) {
                        throw new Exception("Error: Something went wrong with the search.");
                    }
                    var hierarchy3 = getInstanceHierarchy(hierarchyIndex, caex);
                    writeToCell(dataToWrite3, hierarchy3); // write new data to cell
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
                case "INTERNALLINKS":
                    //trickle down
                case "SUBCLASS":
                    //trickle down
                case "CREATE CLASS":
                    //output.result = "NOT IMPLEMENTED YET, MAYBE NEVER, WHO KNOWS";
                    throw new Exception("Error: The command you trying to use is not implemented");
            
                default:
                    throw new Exception($"Error: Switch does not know about that the job {payload.function_name}");

            }

            caex.SaveToFile(@payload.path, true);

            return output;
        }

        private string writeToCell(string data, InstanceHierarchyType hierarchy) {
            var dataOld = hierarchy.InternalElement;
            //hierarchy.InternalElement. = data; || FIXME: Element ist schreibgeschützt, suche Methode zum Schreiben
            if(dataOld != null) {
                return $"Changed data from {dataOld} to {data}.";   
            } else {
                return $"Changed cell data to {data}";
            }
        }

        private InstanceHierarchyType searchForElement(string element, CAEXDocument caex) {
            foreach(var instanceHierarchy in caex.CAEXFile.InstanceHierarchy) {
                if(instanceHierarchy.InternalElement.ElementName == element) {
                    return instanceHierarchy;
                }
                //foreach(var internalElement in instanceHierarchy.InternalElement) {
                    //if(internalElement == element) {
                    //    return internalElement.instanceHierarchy; // dont know, if possible?
                  //  }                       
                //}

            }
            throw new Exception("element not found!");
        }

        private InstanceHierarchyType getInstanceHierarchy(string indexer, CAEXDocument caex)
        {
            return caex.CAEXFile.InstanceHierarchy[indexer];
        }
    }
}
