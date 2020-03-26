var edge = require('edge-js');
var adapter = edge.func('./dlls/Adapter.dll');

function call(name, input) {
    adapter({name: name, input: input}, function (error, result) {
        if (error) throw error;
        if (result) {
            console.log("call was successful");
        }
    });
}

module.exports = {
    call,
};