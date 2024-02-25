#include <stdio.h>
#include <stdlib.h>


/** just add money to account */
void incomeWithoutTax(double amount,double* account){
	*account += amount;
}

/** calculate account value add income with tax
 *  0-20=0% - 20-50=10% - 50-200=20% - 200+=40%
 */
double incomeWithTax(double amount,double* account){
	double tax = 0.0f;
	if(amount > 20){
		if(amount > 50){
			if(amount > 200){	//income 200+
				tax = (3 + 30 + (amount-200)/100*40);
				incomeWithoutTax((amount-tax),account);
			} else{				//income 50-200
				tax = (3 + (amount-50)/100*20);
				incomeWithoutTax((amount-tax),account);
			}
		} else {				//income 20-50
			tax = (amount-20)/100*10;
			incomeWithoutTax((amount-tax),account);
		}
	} else {					// income 0-20
		incomeWithoutTax(amount, account);
	}
	printf("\nGezahlte Steuern: %.02lf Euro", tax);
	return (amount-tax);
}

double expenses(double amount,double* account){
	if(amount > *account){
		printf("\nDiese Kosten koennen nicht bezahlt werden.");
		return 0;
	}
	*account -= amount;
	return amount;
}

void addStat(int* counter, double* sum, double amout){
	if(amout > 0){
		*counter += 1;
		*sum += amout;
	}
}

int calcStats(int countIncome, int countExpenses, double* sumIncome, double* sumExpenses){
	if(countIncome > 0){
		*sumIncome = *sumIncome/countIncome;
	}
	if(countExpenses > 0){
		*sumExpenses = *sumExpenses/countExpenses;
	}
	return 0;
}

int main()
{
	double account = 100.00f;
	char action = ' ';
	double amount = 0.0f;

	// statistic values
	int countIncome = 0;
	int countExpenses = 0;
	double sumIncome = 0.0f;
	double sumExpeses = 0.0f;
	double sumTax = 0.0f;
	double tmpSwitch = 0.0f;

	/**
	* 'e' : Einnahme (besteuert)
	* 's' : Steuerfreie Einnahme
	* 'k' : Kosten
	*/

	while(action != '='){

		printf("\nGuthaben: %.2f Euro", account);

		printf("\nTyp: ");
		scanf(" %c", &action);
		if(action == '=') continue;

		printf("\nBetrag in Euro: ");
		scanf("%lf", &amount);
		if(amount < 0){
			printf("\nDer Betrag kann nicht negativ sein.");
			continue;
		}

		switch (action) {
			case 'e':
				tmpSwitch = incomeWithTax(amount, &account);
				addStat(&countIncome,&sumIncome, tmpSwitch);
				sumTax += (amount-tmpSwitch);
				break;
			case 's':
				incomeWithoutTax(amount, &account);
				addStat(&countIncome,&sumIncome,amount);
				break;
			case 'k':
				tmpSwitch = expenses(amount, &account);
				addStat(&countExpenses,&sumExpeses,tmpSwitch);
				break;
			default:
				break;
		}


	}

	calcStats(countIncome,countExpenses,&sumIncome,&sumExpeses);
	printf("\nRestguthaben: %.2f Euro", account);
	printf("\n%d Einnahmen mit durchschnittlichem Wert %.02lf Euro", countIncome, sumIncome);
    printf("\n%d Ausgaben mit durchschnittlichem Wert %.02lf Euro", countExpenses, sumExpeses);
    printf("\nGezahlte Steuern: %.02lf Euro", sumTax);

    return 0;
}
