#include <stdio.h>

void calculateFuel(int fuel, int consumption, int recharge, int solarBonus, int planet, int totalPlanets){
    if (fuel <= 0){
        printf("Fuel depleted before reaching Planet %d. Mission Failed!\n", planet);
        return;
    }
    if (planet > totalPlanets){
        printf("Journey completed successfully! Final Fuel = %d\n", fuel);
        return;
    }
    fuel -= consumption;
    fuel += recharge;
    if (planet % 4 == 0){
        fuel += solarBonus;
        printf("(Solar Recharge Applied!)\n");
    }
    if (fuel < 0){
        fuel = 0;
    }
    printf("Planet %d: Fuel Remaining = %d\n", planet, fuel);
    calculateFuel(fuel, consumption, recharge, solarBonus, planet + 1, totalPlanets);
}

void valueInput(){
    int fuel, consumption, recharge, solarBonus, totalPlanets;
    printf("\nEnter initial fuel level: ");
    scanf("%d", &fuel);
    printf("Enter fuel consumption per planet: ");
    scanf("%d", &consumption);
    printf("Enter gravitational recharge per planet: ");
    scanf("%d", &recharge);
    printf("Enter solar recharge bonus (every 4th planet): ");
    scanf("%d", &solarBonus);
    printf("Enter number of planets to travel: ");
    scanf("%d", &totalPlanets);
    printf("\n===== Spacecraft Fuel Simulation =====\n");
    calculateFuel(fuel, consumption, recharge, solarBonus, 1, totalPlanets);
}

int main(){
    int choice;
    do{
        printf("\n======== SPACECRAFT FUEL MENU ========\n");
        printf("1. Run Fuel Simulation\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                valueInput();
                break;
            case 2:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 2);
    return 0;
}
