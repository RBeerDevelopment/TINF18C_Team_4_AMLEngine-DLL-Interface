var edge = require('edge-js');
    var function_library_interface_cs= edge.func({
    source: function () {/*
    
        using Aml.Engine;
        using Aml.Engine.CAEX;
        using System.Data;
        using System.Threading.Tasks;
        using System;
 

        public class Startup
        {
            public async Task<object> Invoke(object input)
            {
                Action<object> action = (object obj) =>
                                {
                                   Console.WriteLine("NANNAN",Task.CurrentId, obj);
                                };
                Task t = new Task(action, "alpha");

                //var caexDocument = CAEXDocument.LoadFromFile("C:/DHBW/UniDevelopment/Semester 3/SWE/src/BeispielDateien/AutomationMLBaseRoleClassLib.aml");
                var caexDocument = CAEXDocument.New_CAEXDocument();
                caexDocument.SaveToFile("build/myfile.aml", true);

                Console.WriteLine("test32");
                t.Start();
                return t;
            }
        }
    */
    },
    references: ['dlls/AML.Engine.dll', 'System.Data.dll']
    });
    