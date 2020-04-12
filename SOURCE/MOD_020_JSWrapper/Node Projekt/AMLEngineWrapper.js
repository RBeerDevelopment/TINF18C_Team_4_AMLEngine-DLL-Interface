var edge = require('edge-js');
var adapter = edge.func('./dlls/Adapter.dll');

function call(functionName, path, input = {}, callback = null) {
    console.log({function_name: functionName, path: path, ...input});
    adapter({function_name: functionName,  ...input}, function (error, result) {
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

function createTestFile(callback = null) {
    call("createTestFile", {}, callback);
}

function loadFromFile(filePath, callback = null) {
    call("loadFromFile", {filepath: filePath}, callback);
}

function saveToFile(CAEXDocument, filePath, callback = null) {
    call("saveToFile", {caex: CAEXDocument, filepath: filePath}, callback);
}

function appendToInstanceHierarchy(CAEXDocument, instanceName, internalElement, callback = null) {
    call("instanceHierarchy_Append", {
        caex: CAEXDocument,
        instance: instanceName,
        internalelement: internalElement
    }, callback);
}

function getInstanceHierarchy(CAEXDocument, index, callback = null) {
    call("instanceHierarchy_Get", {caex: CAEXDocument, getValue: index}, callback);
}

module.exports = {
    call,
    createTestFile,
    loadFromFile,
    saveToFile,
    appendToInstanceHierarchy,
    getInstanceHierarchy,
};