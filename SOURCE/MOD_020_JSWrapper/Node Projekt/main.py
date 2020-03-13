# Copy each file from /src and build them into out_file 
# run with "python main.py" in console
# at some point can be build as exe

src_path="./src"
out_file="./build/out.js"



# __________________________
from os import listdir
from os.path import isfile, join

onlyfiles = [f for f in listdir(src_path) if isfile(join(src_path, f))]

js_file="var edge = require('edge-js');"

print(onlyfiles)

for i in range(len(onlyfiles)):
    f_path=src_path+"/"+onlyfiles[i]

    c_code=""
    with open(f_path,"r") as f:
        c_code=f.read()
    
    js_function ="""
    var function_"""+onlyfiles[i].replace(".","_")+"""= edge.func({
    source: function () {/*
    """+c_code+"""
    */
    },
    references: ['dlls/AML.Engine.dll', 'System.Data.dll']
    });
    """
    js_file+=js_function


with open(out_file,"w") as f:
    f.write(js_file)

# SOURCES
# https://stackoverflow.com/questions/3207219/how-do-i-list-all-files-of-a-directory