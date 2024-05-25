
int cantidad, personas_bebidas;
int* montos = new int[cantidad];
void gen_random() {
 srand(time(0));
 for (int i = 0; i < cantidad; i++) {
 montos[i] = rand() % (25, 500);
 if (montos[i] >= 100 && montos[i] <= 300) {
 personas_bebidas++;
 }
 }
}
void ordenar_montos() {
 for (int i = 0; i < cantidad; i++) {
 int llave = montos[i];
 int j = i - 1;
 while (j >= 0 && montos[j] > llave) {
 montos[j + 1] = montos[j];
 j = j - 1;
 }
 montos[j + 1] = llave;
 }
}
int main() {
 cout << "[+] Ingrese la cantidad de personas: " << endl; cin >> cantidad;
 gen_random();
 cout << "Cantidad de personas bebidas: " << personas_bebidas << endl;
 ordenar_montos();
 for (int i = 0; i < cantidad; i++) {
 if (montos[i] % 2 == 0) {
 cout << "monto con cantidad par: " << montos[i]<< "\t";
 }
 }
 for (int i = 0; i < cantidad; i++) {
 cout << " [" << montos[i] << "] \t ";
 }
 return 0;
}
