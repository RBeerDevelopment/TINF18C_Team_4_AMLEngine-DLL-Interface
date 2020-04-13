var edge = require('edge-js');
var adapter = edge.func('./dlls/Adapter.dll');

function call(functionName, path, input = {}, callback = null) {
    //console.log({function_name: functionName, path: path, ...input});
    adapter({function_name: functionName, path: path, ...input}, function (error, result) {
        if (error) throw error;
        if (result) {
            if(callback) {
                callback(result);
            }
            else {
                return result;
            }
        }
    });
}

// Usage examples of all supported functions
// Also allows a developer to look through all supported functions using code completion

function createTestFile(path, callback = null) {
    call("createTestFile", path, {}, callback);
}

function appendToInstanceHierarchy(path, instanceName, internalElement, callback = null) {
    call("instanceHierarchy_Append", path, {
        instance: instanceName,
        internalelement: internalElement
    }, callback);
}

function getInstanceHierarchy(path, index, callback = null) {
    call("instanceHierarchy_Get", path, {indexer: index}, callback);
}

function createSystemUnitClass(path, unitClassLibName, unitClassName = null, index = null, callback = null) {
    if(unitClassName == null) {
        call("create_systemUnitClass", path, {unitclasslib_name: unitClassLibName}, callback);
    }
    else if (index == null){
        call("create_systemUnitClass", path, {
            unitclasslib_name: unitClassLibName,
            unitclass_name: unitClassName
        }, callback);
    }
    else {
        call("create_systemUnitClass", path, {
            unitclasslib_name: unitClassLibName,
            unitclass_name: unitClassName,
            indexer: index
        }, callback);
    }
}

function createInterfaceClass(path, interfaceClassName, interfaceName = null, callback = null) {
    if(interfaceName == null) {
        call("create_interfaceClass", path, {interface_classname: interfaceClassName}, callback);
    }
    else {
        call("create_interfaceClass", path, {
            interface_classname: interfaceClassName,
            iface_name: interfaceName
        }, callback);
    }
}

function appendInstanceElement(path, index, instanceElement, callback = null) {
    call("instanceElement_append", path, {
        indexer: index,
        inElement: instanceElement
    }, callback);
}

function validate(path, callback = null) {
    call("validate", path, {}, callback);
}

function repair(path, callback = null) {
    call("repair", path, {}, callback);
}

module.exports = {
    call,
    createTestFile,
    appendToInstanceHierarchy,
    getInstanceHierarchy,
    createSystemUnitClass,
    createInterfaceClass,
    appendInstanceElement,
    validate,
    repair,
};