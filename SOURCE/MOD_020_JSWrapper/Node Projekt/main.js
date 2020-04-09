wrapper = require('./AMLEngineWrapper.js');

function logResult(result) {
    console.log(`Call returned: ${result}`);
}

// Example call
wrapper.call("createTestFile", {path: "./build/Lucas_ist_ein_doofi.aml"}, logResult);
