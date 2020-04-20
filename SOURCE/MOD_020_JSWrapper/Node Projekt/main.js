
wrapper = require('./AMLEngineWrapper.js');

function logResult(result) {
    console.log(`Call returned: ${result}`);
}


wrapper.call("createTestFile", 1);
