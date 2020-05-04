var edge = require('edge-js');
var adapter = edge.func('./node_modules/amlenginewrapper/dlls/Adapter.dll');

function call(functionName, path, input = {}, callback = null) {
    adapter({function_name: functionName, path: path, ...input}, function (error, result) {
        if (error) throw error;
        if (result) {
            if(callback) {
                return callback(result);
            }
            else {
                return result;
            }
        }
    });
}

// Usage examples of all supported functions
// Also allows a developer to look through all supported functions using code completion
function appendToInstanceHierarchy(path, index, internalElement = null, callback = null) {
    if(internalElement == null) {
        return call("instanceHierarchy_Append", path, {
            indexer: index
        }, callback);
    }
    else {
        return call("instanceHierarchy_Append", path, {
            indexer: index,
            internalelement: internalElement
        }, callback);
    }
}

function getInstanceHierarchy(path, index, callback = null) {
    return call("instanceHierarchy_Get", path, {indexer: index}, callback);
}

function createSystemUnitClass(path, unitClassLibName, unitClassName = null, index = null, callback = null) {
    if(unitClassName == null) {
        return call("create_systemUnitClass", path, {unitclasslib_name: unitClassLibName}, callback);
    }
    else if (index == null){
        return call("create_systemUnitClass", path, {
            unitclasslib_name: unitClassLibName,
            unitclass_name: unitClassName
        }, callback);
    }
    else {
        return call("create_systemUnitClass", path, {
            unitclasslib_name: unitClassLibName,
            unitclass_name: unitClassName,
            indexer: index
        }, callback);
    }
}

function createInterfaceClass(path, interfaceClassName, interfaceName = null, callback = null) {
    if(interfaceName == null) {
        return call("create_interfaceClass", path, {interface_classname: interfaceClassName}, callback);
    }
    else {
        return call("create_interfaceClass", path, {
            interface_classname: interfaceClassName,
            iface_name: interfaceName
        }, callback);
    }
}

function appendInstanceElement(path, index, instanceElement, callback = null) {
    return call("instanceElement_append", path, {
        indexer: index,
        inElement: instanceElement
    }, callback);
}

function renameElement(path, indexer, newName, internalElement, callback = null) {
    return call("rename_element", path, {
        indexer: indexer,
        newName: newName,
        ie: internalElement
    }, callback);
}

function validate(path, callback = null) {
    return call("validate", path, {}, callback);
}

function repair(path, callback = null) {
    return call("repair", path, {}, callback);
}

module.exports = {
    call,
    appendToInstanceHierarchy,
    getInstanceHierarchy,
    createSystemUnitClass,
    createInterfaceClass,
    appendInstanceElement,
    renameElement,
    validate,
    repair,
};