var edge = require('edge-js');
//var dll = edge.func('./dlls/startUp.cs');
var dll = edge.func('./dlls/Adapter.dll');
dll({i: 1, c: 2}, function (error, result) {
    if (error) throw error;
    console.log(result);
});
//console.log(dll);
