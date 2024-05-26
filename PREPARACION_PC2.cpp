
int nproveedores=0;
int* provedores = new int[nproveedores]; int promedio;


void ingresar_datos() {
	cout << "Ingrse el numero de proveedores " << endl; cin >> nproveedores;
	for (int i = 0; i < nproveedores; i++) {
		cout << "Ingrese el monto: "; cin >> provedores[i];
		promedio += provedores[i];
	}
}

void calcular_promedio() {
	promedio = promedio / nproveedores;
}


int mayor_compras() {
	int max = 0, min = 0, indice = 0;
	for (int i = 0; i < nproveedores; i++) {
		if (provedores[i] > max) {
			max = provedores[i];
			indice=i;
		}
	}
	return indice;
}

int menor_compras() {
	int min = INT_MAX, indice=0;
	for (int i = 0; i < nproveedores; i++) {
		if (provedores[i] < min) {
			min = provedores[i];
			indice = i;
		}
	}
	return indice;
}

void ordenamiento_tipo_sort() {
	int current = 0, j = 0;
	for (int i = 0; i < nproveedores; i++){
		current = provedores[i];
		j = i - 1;

		while (j >= 0 && provedores[j] > current) {
			provedores[j + 1] = provedores[j];
			j -= 1;
		}

		provedores[j + 1] = current;
	}
}

void mostrar_datos() {
	for (int i = 0; i < nproveedores; i++) {
		cout << " [" << provedores[i] << "] ";
	}
}


int main() {
	ingresar_datos(); calcular_promedio();
	cout << "Prmedio: " << promedio << endl;
	cout << "Mayor compras: " << provedores[mayor_compras()] << endl;
	cout << "Menor compras: " << provedores[menor_compras()] << endl;
	ordenamiento_tipo_sort();
	mostrar_datos();
}
