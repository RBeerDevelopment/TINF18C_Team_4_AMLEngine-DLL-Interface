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

            //Console.WriteLine($"This is the payload function_name: {payload.function_name}");
            if (!GlobalHelper.dynamicPayloadHasKeys(payload, new[] { "function_name", "path" }))
                throw new Exception("Error: function_name and path expected");

            Console.WriteLine($"Calling function {payload.function_name}");
            Console.WriteLine($"Path to CAEX {payload.path}");


            //output to give back
            string output = string.Empty;

            // global caex document to work with
            CAEXDocument caex = CaexOpener.OpenCaexSafe(@payload.path);

            if (caex == null)
            {
                output = "Cannot open file, ERROR occured";
                Console.WriteLine("Stopping c# programm...");

                output = "Cannot open file, ERROR occured";
                throw new Exception("Error: Cannot open file");
            }

            Console.WriteLine(payload.function_name);
            switch ((payload.function_name as string).ToUpper())
            {

                case "INSTANCEHIERARCHY_APPEND":
                    if (!GlobalHelper.dynamicPayloadHasKeys(payload,"instance"))
                        throw new Exception("Error: name for the instance expected");

                    var hierarchyInstanceName = payload.instance;

                    // only string or Array of Tupels (key,value)
                    var hierarchyInstance = caex.CAEXFile.InstanceHierarchy.Append(hierarchyInstanceName);



                    if (GlobalHelper.dynamicPayloadHasKeys(payload, "internalelement"))
                        hierarchyInstance.InternalElement.Append(payload.internalelement);


                    output = $"Created instance hierarchy {hierarchyInstanceName} on file";
                    break;

                case "INSTANCEHIERARCHY_GET":
                    if (!GlobalHelper.dynamicPayloadHasKeys(payload, "indexer"))
                        throw new Exception("Error: name for the indexer to return expected");
                    // int oder string oder Tupel (Name:"Version", Value:"1.0") auf Internes Element von Instanz

                    var indexer = payload.indexer;
                    var hierarchy = getInstanceHierarchy(indexer, caex);

                    output = hierarchy.ToString();
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
                                output = $"Created UnitclassLib {lib_name}, created systemunitclass {class_name} and attached to hierarchy{indexer}";
                            }
                            else
                            {
                                output = $"Created UnitclassLib {lib_name} and created systemunitclass {class_name}";
                            }

                        }
                        else
                        {
                            output = $"Created UnitclassLib {lib_name}";
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

                            output = $"Created Interface-class {iface_classname} and Interface {iface_name}";
                        }
                        else
                        {
                            output = $"Created Interface-class {iface_classname}";
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
                    output = $"Created new internal element named {payload.inElement}";
                    break;

                /*
                 * his case renames an internal element.
                 */
                case "RENAME_ELEMENT":
                    Console.Write("In rename_element");
                    if(!GlobalHelper.dynamicPayloadHasKeys(payload, "indexer")) {
                        throw new Exception("Error: name for indexer is missing");
                    } else if(!GlobalHelper.dynamicPayloadHasKeys(payload, "newName")) {
                        throw new Exception("Error: no \"newName\" found");
                    } else if (!GlobalHelper.dynamicPayloadHasKeys(payload, "ie"))
                    {
                        throw new Exception("Error: name of internal element is missing (key is \"ie\"");
                    }
                   
                    var indexer2 = payload.indexer;
                   
                    var hierarchy2 = getInstanceHierarchy(indexer2, caex);
                   
                    var newIE = payload.newName;
                    var nameOfIEToReplace = payload.ie;
        
                    var oldIE = findInternalElement(hierarchy2, caex, nameOfIEToReplace);
                    if(oldIE == null)
                    {
                        throw new Exception("The internal element was not found.");
                    }

                    oldIE.Name = newIE;

              
                    if(nameOfIEToReplace != null) {
                        oldIE.Name = newIE;
                        output = $"Changed \"newName\" from {nameOfIEToReplace} to {newIE}.";   
                    }
               
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
                    output = validator.validate(caex, payload.path);
                    break;

                case "REPAIR":
                    validator = new Validator();

                    output = validator.validate_and_repair(caex, payload.path);
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
            Console.WriteLine("in getInstanceHier");
            var hierarchy= caex.CAEXFile.InstanceHierarchy[indexer];
            Console.WriteLine("in getInstanceHier/" + indexer + "/" + hierarchy);
            if (hierarchy == null)
            {
                Console.WriteLine("in getInstanceHierNULL");
                throw new Exception($"Cannot find InstanceHierarchyType {indexer}");
            }
            return hierarchy;
        }

        /**
        * This function searches for an internal element with a given name in a given hierarchy. Children of internal elements
        * get searched aswell.
        */
        private InternalElementType findInternalElement(InstanceHierarchyType hierarchy, CAEXDocument caex, string nameOfElement)
        {
            // Cycle through alle children elements in the hierarchy
            foreach (var internalElement in hierarchy)
            {
            
                if(internalElement.Name == nameOfElement) // element found
                {
                    return internalElement;
                } else // element is not the searched for element
                {
            
                    var cycleResult  = cycleElements(internalElement, nameOfElement); // cycle through descendants
            
                    if(cycleResult.Name != null){ // element was found in the descendants
                        return cycleResult;
                    } 
                }
                
            }
            throw new Exception("No internal elements for this indexer " + hierarchy);
        
        }

        /**
         * This function is a recursive hekper function for findInternalElement and cycles through the children
         * of a given internal element until the sought-after is found or until there are no more descendants.
         */
        private InternalElementType cycleElements(InternalElementType ie, string nameToBeSearched)
        {
            
            foreach (var internalElementChild in ie.InternalElement) // cycle through children
            {
                if (internalElementChild.Name == nameToBeSearched) // element found
                {
                    return internalElementChild;
                }
                else
                {
                    if(internalElementChild.InternalElement != null) // element has children
                    {
                        var ieToReturn = cycleElements(internalElementChild, nameToBeSearched); // start recursion
                        if (ieToReturn.Name != null) // found element in children
                        {
                            return ieToReturn;
                        }
                    } 
                }
            }
            return new InternalElementType(new System.Xml.Linq.XElement("NULL")); // cant return null element, therefor return useless element

        }

    }
}
