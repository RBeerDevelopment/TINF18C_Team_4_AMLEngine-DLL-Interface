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
##### Description
This function offers the possibility to directly call a function inside the wrapper. Only use this function if you really have to. Most of the time using one of the functions below will be more convenient
##### Parameters
| Parameter | Description |
|-----------|-------------|
|functionName|The name of the function you want to call|
|path|The path to the AML file you want to use|
|input|The payload required by the function you want to use in JSON notation<br />**Default value:** {}|
|callback|The callback function that should handle the result of this function call.<br />If no callback is specified the result will be returned by using a return statement.<br />*See [How to handle the result of a function call](#how-to-handle-the-result-of-a-function-call) for more information.*<br />**Default value:** null|
##### Return value
This function returns what ever is specified for the function you specified
<hr />

### appendToInstanceHierarchy
````
wrapper.appendToInstanceHierarchy(path, instanceName, 
  internalElement = null, callback = null);
````
##### Description
This function appends a new instance hierarchy
##### Parameters
| Parameter | Description |
|-----------|-------------|
|path|The path to the AML file you want to use|
|instanceName|The name of the instance you want to append|
|internalElement|The internalElement you want to include in the instance hierarchy|
|callback|The callback function that should handle the result of this function call.<br />If no callback is specified the result will be returned by using a return statement.<br />*See [How to handle the result of a function call](#how-to-handle-the-result-of-a-function-call) for more information.*<br />**Default value:** null|
##### Return value
This function returns a confirmation message, letting you know whether the operation was successful
<hr />

### getInstanceHierarchy
````
wrapper.getInstanceHierarchy(path, index, callback = null);
````
##### Description
This function returns a hierarchy element as string
##### Parameters
| Parameter | Description |
|-----------|-------------|
|path|The path to the AML file you want to use|
|index|The index of the instanceHierarchy you are trying to get|
|callback|The callback function that should handle the result of this function call.<br />If no callback is specified the result will be returned by using a return statement.<br />*See [How to handle the result of a function call](#how-to-handle-the-result-of-a-function-call) for more information.*<br />**Default value:** null|
##### Return value
This function returns the InstanceHierarchy you were trying to get as a string
<hr />

### createSystemUnitClass
````
wrapper.createSystemUnitClass(path, unitClassLibName,
  unitClassName = null, index = null, callback = null);
````
##### Description
This function creates a new system unit class
##### Parameters
| Parameter | Description |
|-----------|-------------|
|path|The path to the AML file you want to use|
|unitClassLibName|The name of the new SystemUnitClassLib|
|unitClassName|The name of a UnitClass you want to include in the SystemUnitClassLib<br />**Default value:** null|
|index|The index of the SystemUnitClass<br />**Default value:** null|
|callback|The callback function that should handle the result of this function call. <br />If no callback is specified the result will be returned by using a return statement.<br />*See [How to handle the result of a function call](#how-to-handle-the-result-of-a-function-call) for more information.*<br />**Default value:** null|
##### Return value
This function returns a confirmation message, letting you know whether the operation was successful
<hr />

### createInterfaceClass
````
wrapper.createInterfaceClass(path, interfaceClassName,
  interfaceName = null, callback = null);
````
##### Description
This function creates a new interface class
##### Parameters
| Parameter | Description |
|-----------|-------------|
|path|The path to the AML file you want to use|
|interfaceClassName|The name of the new InterfaceClass|
|interfaceName|The name of an interface you want to include<br />**Default value:** null|
|callback|The callback function that should handle the result of this function call.<br />If no callback is specified the result will be returned by using a return statement.<br />*See [How to handle the result of a function call](#how-to-handle-the-result-of-a-function-call) for more information.*<br />**Default value:** null|
##### Return value
This function returns a confirmation message, letting you know whether the operation was successful
<hr />

### appendInstanceElement
````
wrapper.appendInstanceElement(path, index, 
  instanceElement, callback = null);
````
##### Description
This function appends a new instance element
##### Parameters
| Parameter | Description |
|-----------|-------------|
|path|The path to the AML file you want to use|
|index|The index of the InstanceHierarchy you want to append to|
|instanceElement|The name of the instanceElement you want to append|
|callback|The callback function that should handle the result of this function call.<br />If no callback is specified the result will be returned by using a return statement.<br />*See [How to handle the result of a function call](#how-to-handle-the-result-of-a-function-call) for more information.*<br />**Default value:** null|
##### Return value
This function returns a confirmation message, letting you know whether the operation was successful
<hr />

### changeData
````
wrapper.changeData(path, index, data, callback = null);
````
##### Description
This function rewrites the content of a given element
##### Parameters
| Parameter | Description |
|-----------|-------------|
|path|The path to the AML file you want to use|
|index|The index of the instanceElement you want to change|
|data|The new data you want to enter|
|callback|The callback function that should handle the result of this function call.<br />If no callback is specified the result will be returned by using a return statement.<br />*See [How to handle the result of a function call](#how-to-handle-the-result-of-a-function-call) for more information.*<br />**Default value:** null|
##### Return value
This function returns a confirmation message, letting you know whether the operation was successful
<hr />

### searchAndChangeContent
````
wrapper.searchAndChangeContent(path, searchWord, data, callback = null);
````
##### Description
This function does the same as *changeData*, but instead of an actual index, it searches through the whole document and changes the data of a found element
##### Parameters
| Parameter | Description |
|-----------|-------------|
|path|The path to the AML file you want to use|
|searchWord|The name of the element that should be searched for|
|data|The new data you want to enter|
|callback|The callback function that should handle the result of this function call.<br />If no callback is specified the result will be returned by using a return statement.<br />*See [How to handle the result of a function call](#how-to-handle-the-result-of-a-function-call) for more information.*<br />**Default value:** null|
##### Return value
This function returns a confirmation message, letting you know whether the operation was successful
<hr />

### validate
````
wrapper.validate(path, callback = null);
````
##### Description
This function simply validates a file on a given path
##### Parameters
| Parameter | Description |
|-----------|-------------|
|path|The path to the AML file you want to validate|
|callback|The callback function that should handle the result of this function call.<br />If no callback is specified the result will be returned by using a return statement.<br />*See [How to handle the result of a function call](#how-to-handle-the-result-of-a-function-call) for more information.*<br />**Default value:** null|
##### Return value
This function returns the result of the validation
<hr />

### repair
````
wrapper.repair(path, callback = null);
````
##### Description
This function validates and repairs a given document
##### Parameters
| Parameter | Description |
|-----------|-------------|
|path|The path to the AML file you want to repair|
|callback|The callback function that should handle the result of this function call.<br />If no callback is specified the result will be returned by using a return statement.<br />*See [How to handle the result of a function call](#how-to-handle-the-result-of-a-function-call) for more information.*<br />**Default value:** null|
##### Return value
This function returns the result of the repair
