const vscode = require('vscode');

function activate(context) {
    vscode.window.showInformationMessage(`u/activate`);
}

function deactivate(context) {
    vscode.window.showInformationMessage(`u/deactivate`);
}

module.exports = {
    activate,
    deactivate
};
