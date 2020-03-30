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
            Console.WriteLine($"Calling function {payload.name}");
            Console.WriteLine($"With {payload.input}");


            dynamic output=new object();

            switch (((string)payload.name).ToUpper())
            {
                case "CREATETESTFILE":
                    var caexDocument = CAEXDocument.New_CAEXDocument();
                    caexDocument.SaveToFile("build/Lucas_ist_ein_doofi.aml", true);
                    break;

                case "LOADFROMFILE":
                    var filepath = (string)payload.filepath;
                    caexDocument = CAEXDocument.LoadFromFile(filepath);

                    output.caexdocument = caexDocument;
                    break;

                case "SAVETOFILE":
                    filepath = payload.filepath;
                    caexDocument = payload.caex;
                    caexDocument.SaveToFile(filepath, true);
                    break;


                case "INSTANCEHIERARCHY_APPEND":
                    var hierarchyInstanceName = payload.instance;

                    caexDocument = payload.caex;
                    
                    // nur Name oder Array von Tupel (key,value) hinten rein
                    var hierarchyInstance=caexDocument.CAEXFile.InstanceHierarchy.Append(hierarchyInstanceName);


                    //ggf. Internal element hinzufügen, checken ob benötigt??? https://stackoverflow.com/questions/2839598/how-to-detect-if-a-property-exists-on-an-expandoobject

                    if (((IDictionary<String, object>)payload).ContainsKey("internalelement"))
                    {
                        hierarchyInstance.InternalElement.Append(payload.internalelement);
                    }
                    break;

                case "INSTANCEHIERARCHY_GET":
                    caexDocument = payload.caex;

                    // int oder string oder Tupel (Name:"Version", Value:"1.0") auf Internes Element von Instanz
                    var indexer = payload.getValue;

                    output.hierarchyinstance = caexDocument.CAEXFile.InstanceHierarchy[indexer];

                    break;

                // TRAVERSING ???
                //REPAIR ???


                    //var myIH = document.CAEXFile.InstanceHierarchy.Append("myIH");


                    default:
                    break;
            }


            if (payload.name == "createTestFile")
            {
                var caexDocument = CAEXDocument.New_CAEXDocument();
                caexDocument.SaveToFile("build/Lucas_ist_ein_doofi.aml", true);
            }
            //CAEXDocument.LoadFromFile;

            return true;
        }
    }
}
