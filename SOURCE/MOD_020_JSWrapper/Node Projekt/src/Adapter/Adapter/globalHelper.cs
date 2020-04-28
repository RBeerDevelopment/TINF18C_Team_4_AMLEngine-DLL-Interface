using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Adapter
{
    public static class GlobalHelper
    {
        public static bool dynamicPayloadHasKeys(dynamic payload, string key)
        {
            var pay = (IDictionary<String, object>)payload;
            if (pay.ContainsKey(key))
            {
                object value;
                pay.TryGetValue(key, out value);
                string str = value?.ToString();

                if (String.IsNullOrEmpty(str))
                {
                    Console.WriteLine($"Info:  The payload does contain the {key}, but it is empty (or cannot read it).");
                    return false;
                }


                return true;

            }

            Console.WriteLine($"Info: The payload doesn't contain the {key} key");
            return false;
        }
        public static bool dynamicPayloadHasKeys(dynamic payload, Array parameter)
        {
            foreach (string item in parameter)
            {
                if (!dynamicPayloadHasKeys(payload, item))
                    return false;

            }
            return true;
        }

    }
}
