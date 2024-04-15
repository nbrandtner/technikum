window.onload = () => {
    const button = document.getElementById('convertButton');

    const input = document.getElementById('input') as HTMLInputElement;

    const output = document.getElementById('output');
    
    const conversionType = document.getElementById('conversionType') as HTMLSelectElement;

    if (button && input && output && conversionType) {
        button.addEventListener('click', () => convertData(input, output, conversionType));
        input.addEventListener('keydown', (event) => {
            if (event.key === 'Enter') {
                convertData(input, output, conversionType);
            }
        });
    } else {
        console.error('One or more elements could not be found.');
    }
}

function convertData(input: HTMLInputElement, output: HTMLElement, conversionType: HTMLSelectElement) {
    if (input.value === '') {
        output.textContent = 'Please enter a value to convert.';
        return;
    }

    const inputValue = parseFloat(input.value);
    let res: number;
    let outputText: string;

    switch (conversionType.value) {
        case 'in-cm':
            res = inputValue * 2.54;
            outputText = `${inputValue} inch${inputValue === 1 ? ' is' : 'es are'} equal to ${res.toFixed(2)} centimeter${res === 1 ? '' : 's'}.`;
            break;
        case 'cm-in':
            res = inputValue / 2.54;
            outputText = `${inputValue} centimeter${inputValue === 1 ? ' is' : 's are'} equal to ${res.toFixed(2)} inch${res === 1 ? '' : 'es'}.`;
            break;
        case 'yd-m':
            res = inputValue * 0.9144;
            outputText = `${inputValue} yard${inputValue === 1 ? ' is' : 's are'} equal to ${res.toFixed(2)} meter${res === 1 ? '' : 's'}.`;
            break;
        case 'm-yd':
            res = inputValue / 0.9144;
            outputText = `${inputValue} meter${inputValue === 1 ? ' is' : 's are'} equal to ${res.toFixed(2)} yard${res === 1 ? '' : 's'}.`;
            break;
        default:
            outputText = 'Please select a valid conversion type.';
            break;
    }

    output.textContent = outputText;
}