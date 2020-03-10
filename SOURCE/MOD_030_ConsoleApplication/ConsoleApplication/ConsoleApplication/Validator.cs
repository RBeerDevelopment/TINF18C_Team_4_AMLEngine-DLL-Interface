using Aml.Engine.CAEX;
using Aml.Engine.Services;
using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication
{
    public class Validator
    {
        public Validator(int logLevel)
        {
            this.LogLevel = logLevel;
        }

        // ???
        public int LogLevel { get; set; }

        public bool validate(CAEXDocument doc)
        {
            /*
             Validate and log Errors with parsing here
             */
            ValidatorService service = ValidatorService.Register();

            var validationElements = service.ValidateAll(doc);

            // validate all elements (needs an updated Element Registry)
            foreach (var isValidated in validationElements)
            {
                Console.WriteLine(isValidated);
                Console.WriteLine(isValidated.LongDescription);
                Console.WriteLine(isValidated.ValidationInformation);
                Console.WriteLine(isValidated.AvailableRepairOptions);
                
                // check for the GenerateUniqueIDForDoubles - Option to repair
                if (isValidated.AvailableRepairOptions.HasFlag(RepairTypeEnum.GenerateUniqueIDForDoubles))
                {
                    //bool isRepaired = doc.CAEXDocument.Repair(isValidated, RepairTypeEnum.GenerateUniqueIDForDoubles);

                    //if (isRepaired)
                    //{
                    //    // ToDo: display isValidated.RepairResult
                    //}
                }
            }

            throw new NotImplementedException("Stuff");
        }

        private void Error(string message,int _logLevel)
        {
            /*
             writes Error to console ??
             */
        }
    
    }
}
