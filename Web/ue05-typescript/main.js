window.onload = function () {
    var button = document.getElementById('convertButton');
    var input = document.getElementById('input');
    var output = document.getElementById('output');
    var conversionType = document.getElementById('conversionType');
    if (button && input && output && conversionType) {
        button.addEventListener('click', function () { return convertData(input, output, conversionType); });
        input.addEventListener('keydown', function (event) {
            if (event.key === 'Enter') {
                convertData(input, output, conversionType);
            }
        });
    }
    else {
        console.error('One or more elements could not be found.');
    }
};
function convertData(input, output, conversionType) {
    if (input.value === '') {
        output.textContent = 'Please enter a value to convert.';
        return;
    }
    var inputValue = parseFloat(input.value);
    var res;
    var outputText;
    switch (conversionType.value) {
        case 'in-cm':
            res = inputValue * 2.54;
            outputText = "".concat(inputValue, " inch").concat(inputValue === 1 ? ' is' : 'es are', " equal to ").concat(res.toFixed(2), " centimeter").concat(res === 1 ? '' : 's', ".");
            break;
        case 'cm-in':
            res = inputValue / 2.54;
            outputText = "".concat(inputValue, " centimeter").concat(inputValue === 1 ? ' is' : 's are', " equal to ").concat(res.toFixed(2), " inch").concat(res === 1 ? '' : 'es', ".");
            break;
        case 'yd-m':
            res = inputValue * 0.9144;
            outputText = "".concat(inputValue, " yard").concat(inputValue === 1 ? ' is' : 's are', " equal to ").concat(res.toFixed(2), " meter").concat(res === 1 ? '' : 's', ".");
            break;
        case 'm-yd':
            res = inputValue / 0.9144;
            outputText = "".concat(inputValue, " meter").concat(inputValue === 1 ? ' is' : 's are', " equal to ").concat(res.toFixed(2), " yard").concat(res === 1 ? '' : 's', ".");
            break;
        default:
            outputText = 'Please select a valid conversion type.';
            break;
    }
    output.textContent = outputText;
}
