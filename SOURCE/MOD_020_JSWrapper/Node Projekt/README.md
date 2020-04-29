# AMLEngineWrapper
##### *Version 1.0.4*
Wrapper for the [AMLEngine.dll](https://www.nuget.org/packages/Aml.Engine) for [Node.js](https://nodejs.org/)

````
const wrapper = require('amlenginewrapper');

wrapper.validate("path/to/AML-File");
````

# Installation
````
$ npm install amlenginewrapper
````

# Usage
## How to call a function
There are two possible ways to call the functions contained inside this wrapper. The first one is to use the [call()](#call) method of the wrapper and call functions directly. This however requires you to know all required parameters of all the functions you want to use. The easier way to call a functions is to use the predefined handler of that function. The list of supported functions contains usage examples for all of those predifined functions.

## How to handle the result of a function call
### Function calls using return statements
The return value of a function can be accessed by assigning it to a variable, as shown in the example below.
````
var result = wrapper.getInstanceHierarchy(...);
````

### Function calls using callbacks
You can also specify a callback to handle the result of a function, as shown in the example below.
````
function resultHandler(result) {
  console.log(result);
}

wrapper.getInstanceHierarchy(..., resultHandler);
````

### Failed function calls
If a function call fails an error will be thrown, detailing the reason for the error. More information on Node.js handles errors can be found [here](https://nodejs.dev/error-handling-in-nodejs).

## List of supported functions
- [appendToInstanceHierarchy](#appendtoinstancehierarchy)
- [getInstanceHierarchy](#getinstancehierarchy)
- [createSystemUnitClass](#createsystemunitclass)
- [createInterfaceClass](#createinterfaceclass)
- [appendInstanceElement](#appendinstanceelement)
- [changeData](#changedata)
- [searchAndChangeContent](#searchandchangecontent)
- [validate](#validate)
- [repair](#repair)

## Usage examples
### call
````
wrapper.call(functionName, path, input = {}, callback = null);
````

### appendToInstanceHierarchy
````
wrapper.appendToInstanceHierarchy(path, instanceName, internalElement, callback = null);
````

### getInstanceHierarchy
````
wrapper.getInstanceHierarchy(path, index, callback = null);
````

### createSystemUnitClass
````
wrapper.createSystemUnitClass(path, unitClassLibName, unitClassName = null, index = null, callback = null);
````

### createInterfaceClass
````
wrapper.createInterfaceClass(path, interfaceClassName, interfaceName = null, callback = null);
````

### appendInstanceElement
````
wrapper.appendInstanceElement(path, index, instanceElement, callback = null);
````

### changeData
````
wrapper.changeData(path, index, data, callback = null);
````

### searchAndChangeContent
````
wrapper.searchAndChangeContent(path, searchWord, data, callback = null);
````

### validate
````
wrapper.validate(path, callback = null);
````

### repair
````
wrapper.repair(path, callback = null);
````
