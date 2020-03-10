using Aml.Engine.CAEX;
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

        public bool validate(CAEXObject doc)
        {
            /*
             Validate and log Errors with parsing here
             */


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
