using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Adapter
{
    public static class GlobalHelper
    {
        public static bool dynamicPayloadHasKeys(dynamic payload,string key)
        {
            if (((IDictionary<String, object>)payload).ContainsKey(key))
                return true;

            return false;
        }
        public static bool dynamicPayloadHasKeys(dynamic payload,Array parameter)
        {
            foreach (string item in parameter)
            {
                if (!dynamicPayloadHasKeys(payload,item))
                    return false;

            }
            return true;
        }

    }
}
