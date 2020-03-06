var edge = require('edge-js');
const fs = require('fs');

var library_interface_content=""

fs.readFile('library_interface.cs', 'utf8', function(err, contents) {
    // console.log(contents);
    library_interface_content=contents
});

console.log(library_interface_content)

library_interface_content="*/"+library_interface_content+"/*"

var add7 = edge.func({
    source: function () {library_interface_content
    },
    references: ['dlls/AML.Engine.dll', 'System.Data.dll']
});

console.log(add7("test",true))

