//#include <stdio.h>
//#include <stdlib.h>
//#include "LinkedList.h"
#include "Controller.h"
//#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option;
    int flagCarga = 0;
    int flagAdd = 0;
    int flagSave=0;
    char respuesta;
    LinkedList* listaEmpleados = ll_newLinkedList();

    printf("\nCONTROL DE NOMINA DE EMPLEADOS\n");
    do{

    	printf("\nMenu:\n"
    			"\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)"
    			"\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)"
    			"\n3. Alta de empleado"
    			"\n4. Modificar datos de empleado"
    			"\n5. Baja de empleado"
    			"\n6. Listar empleados"
    			"\n7. Ordenar empleados"
    			"\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)"
    			"\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario)"
    			"\n10. Salir");

    	if(ObtenerEntero(&option, "\nIngrese una opcion del menu: ", "Error. Ingrese una opcion que este dentro del menu: ", 1, 10, 1)==0)
    	{
			switch(option)
			{
				case 1:
					if(flagCarga == 0 && controller_loadFromText("data.csv",listaEmpleados)==0)
					{
						flagCarga=1;
						printf("\nEl archivo fue cargado con exito\n");
					}
					else
					{
						if(flagCarga)
						{
							printf("\nEl archivo ya fue cargado\n");
						}
					}
					break;

				case 2:
					if(flagCarga == 0 && controller_loadFromBinary("data.bin" , listaEmpleados)==0)
					{
						flagCarga=1;
						printf("\nEl archivo fue cargado con exito\n");
					}
					else
					{
						if(flagCarga)
						{
							printf("\nEl archivo ya fue cargado\n");
						}
					}
					break;

				case 3:
					if(flagCarga || (flagCarga==0 && ObtenerCaracterDosOpciones(&respuesta, "\nQuiere dar de alta un empleado sin cargar la lista primero? (s-n): ",
							"Error. Ingrese s - n para responder: ", 's','n', 1)==0 && respuesta=='s'))
					{
						if(controller_addEmployee(listaEmpleados)==0)
						{
							flagAdd=1;
						}
						else
						{
							printf("\nError al dar el alta al empleado/a \n");
						}
					}
					break;

				case 4:
					if(flagCarga || flagAdd)
					{
						if(controller_editEmployee(listaEmpleados) != 1)
						{
							printf("\nLa informacion del usuario no ha sido modificada\n");
						}
					}
					else
					{
						printf("\nDebe cargar la lista o dar de alta un empleado/a\n");
					}
					break;

				case 5:
					if(flagCarga || flagAdd)
					{
						controller_removeEmployee(listaEmpleados);
					}
					else
					{
						printf("\nDebe cargar la lista o dar de alta un empleado/a\n");
					}
					break;

				case 6:
					if(flagCarga || flagAdd)
					{
						controller_ListEmployee(listaEmpleados);
					}
					else
					{
						printf("\nDebe cargar la lista o dar de alta un empleado/a\n");
					}
					break;

				case 7:
					if(flagCarga || flagAdd)
					{
						if(controller_sortEmployee(listaEmpleados)==-1)
						{
							printf("\nNo se pudo ordenar la lista de empleado\n");
						}
					}
					else
					{
						printf("\nDebe cargar la lista o dar de alta un empleado/a\n");
					}
					break;

				case 8:
					if(flagCarga == 1 && controller_saveAsText("data.csv",listaEmpleados)==0 &&
							controller_saveAsBinary("data.bin",listaEmpleados)==0)
					{
						flagSave=1;
						printf("\nLa carga ha sido realizada con exito\n");
					}
					else
					{
						if(flagCarga == 0)
						{
							printf("\nRecuerde que debe cargar el archivo antes de guardarlo");
						}
					}
					break;

				case 9:
					if(flagCarga == 1 && controller_saveAsBinary("data.bin",listaEmpleados)==0 &&
							controller_saveAsText("data.csv",listaEmpleados)==0)
					{
						flagSave=1;
						printf("\nLa carga ha sido realizada con exito\n");
					}
					else
					{
						if(flagCarga == 0)
						{
							printf("\nRecuerde que debe cargar el archivo antes de guardarlo");
						}
					}
					break;

				case 10:
					if(ObtenerCaracterDosOpciones(&respuesta, "\nEsta seguro que desea salir del progrma (s-n): ",
							"Error. Ingrese s - n para responder: ", 's','n', 1)==0 && respuesta=='s')
					{
						if(flagSave)
						{
							printf("\nUsted salio del programa\n");
							option=11;
						}
						else
						{
							printf("\nDebe guardar la lista de empleados/as antes de salir del programa\n");
						}
					}
					break;
			}
    	}
	}while(option != 11);
    return 0;
}

