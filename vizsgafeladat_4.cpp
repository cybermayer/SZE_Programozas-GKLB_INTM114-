#include<iostream>
#include<string>

using namespace std;

struct ingredientItem {
    std::string ingredient;
    double quantity;
    ingredientItem* next;
};

ingredientItem* addIngredient(std::string ingredient, double quantity, ingredientItem* food){

        ingredientItem* new_food = new ingredientItem;
        new_food->ingredient = ingredient;
        new_food->quantity = quantity;
        new_food->next = food;
        return new_food;
}

int countElements(const ingredientItem* head){

    int count =0;
    while (head != nullptr){
        count ++;
        head = head->next;
    }
    return count;
}

void deleteIngredients(ingredientItem* head){
    ingredientItem* actual = head;
    while (actual != nullptr){
        head = actual->next;
        delete actual;
        actual = head;
    }
}

void orderLists(ingredientItem* head) {
    if (!head) return; 

    int count = countElements(head);
    cout << "Ez a listaszam: " << count << endl;

    for (int i = 0; i < count - 1; i++) {
        ingredientItem* actual = head;
        bool ordered = true;

        for (int j = 0; j < count - i - 1; j++) {
            if (actual->ingredient > actual->next->ingredient) {
                std::swap(actual->ingredient, actual->next->ingredient);
                std::swap(actual->quantity, actual->next->quantity);
                ordered = false;
            }
            actual = actual->next;
        }
        if (ordered) break;
    }
}

ingredientItem* getAllIngredients(ingredientItem* foods[], int n){

    ingredientItem* total = nullptr;
    for (int i = 0; i < n; i++) {
        ingredientItem* support = foods[i];
        while (support != nullptr) {
            bool already_in = false;
            std::string actual_ing = support->ingredient;
            double actual_quan = support->quantity;

            ingredientItem* current = total;
            ingredientItem* prev = nullptr;

            while (current != nullptr) {
                if (actual_ing == current->ingredient) {
                    current->quantity += actual_quan;
                    already_in = true;
                    break;
                }
                prev = current;
                current = current->next;
            }

            if (!already_in) {
                ingredientItem* newIngredient = new ingredientItem;
                newIngredient->ingredient = actual_ing;
                newIngredient->quantity = actual_quan;
                newIngredient->next = nullptr;

                if (prev == nullptr) {
                    total = newIngredient;
                } else {
                    prev->next = newIngredient;
                }
            }
            support = support->next;
        }
    }
    return total;
}

void compareLists(ingredientItem* first, ingredientItem* second) {

    ingredientItem* comp1 = first;
    ingredientItem* comp2 = second;
    bool same = true;

    while (comp1 != nullptr && comp2 != nullptr) {
        cout << "elso: " << comp1->ingredient << "masodik: " << comp2->ingredient << endl;
        if ((comp1->ingredient != comp2->ingredient) || (comp1->quantity != comp2->quantity)) {
            same = false;
            break;
        }
        comp1 = comp1->next;
        comp2 = comp2->next;
    }

    (same==true) ? cout << "They are the same ones" : cout << "They aren't the same ones";
}

void printLL(const ingredientItem* head){

    while (head!=nullptr)
    {
        cout << "Ingredient: " << head->ingredient << " Quantity: " << head->quantity << endl;
        head = head->next;
    }
}

int main(){

    ingredientItem* f1 = nullptr;
	f1 = addIngredient("flour", 1., f1);
	f1 = addIngredient("sugar", 2., f1);
	f1 = addIngredient("baking powder", 2., f1);
	f1 = addIngredient("salt", .5, f1);
	f1 = addIngredient("milk", 1., f1);
	f1 = addIngredient("butter", 2., f1);
	f1 = addIngredient("egg", 1., f1);
	f1 = addIngredient("oil", 1., f1);

	ingredientItem* f2 = nullptr;
	f2 = addIngredient("butter", 1., f2);
	f2 = addIngredient("sugar", 1., f2);
	f2 = addIngredient("egg", 1., f2);
	f2 = addIngredient("vanilla extract", 2., f2);
	f2 = addIngredient("flour", 2.66, f2);
	f2 = addIngredient("salt", 0.25, f2);

    ingredientItem* exp = nullptr;
	exp = addIngredient("baking powder", 2., exp);
	exp = addIngredient("flour", 3.66, exp);
	exp = addIngredient("sugar", 3., exp);
	exp = addIngredient("salt", 0.75, exp);
	exp = addIngredient("milk", 1., exp);
	exp = addIngredient("butter", 3., exp);
	exp = addIngredient("egg", 2., exp);
	exp = addIngredient("oil", 1., exp);
	exp = addIngredient("vanilla extract", 2., exp);

	ingredientItem* fa[] = { f1, f2 };
    ingredientItem* total = getAllIngredients(fa, 2);
    orderLists(exp);
    orderLists(total);
    compareLists(total, exp);
    deleteIngredients(f1);
    deleteIngredients(f2);
    deleteIngredients(exp);
    deleteIngredients(total);

    return 0;
}
