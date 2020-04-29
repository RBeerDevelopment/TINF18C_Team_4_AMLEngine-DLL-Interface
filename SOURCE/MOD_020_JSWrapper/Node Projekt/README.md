README WIP
# AMLEngineWrapper
##### *1.0.4*
Wrapper for the AMLEngine.dll for Node.js

````
const wrapper = require('amlenginewrapper');

wrapper.validate("path/to/AML-File");
````

# Installation and Import
````
$ npm install amlenginewrapper
````

# Usage
2 possibilities
return management

## Supported functions
- [call](#call)
- [appendToInstanceHierarchy](#appendtoinstancehierarchy)
- [getInstanceHierarchy](#getinstancehierarchy)
- [createSystemUnitClass](#createsystemunitclass)
- [createInterfaceClass](#createinterfaceclass)
- [appendInstanceElement](#appendinstanceelement)
- [changeData](#changedata)
- [searchAndChangeContent](#searchandchangecontent)
- [validate](#validate)
- [repair](#repair)

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
