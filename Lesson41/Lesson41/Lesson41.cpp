/*
Географический справочник

1.Название страны, char[40]
2.Континент, char[25]
3.Столица, char[40]
4.Площадь(млн.кв.км.), float
5.Население(млн.чел.), float

Поиск: по названию страны.
*/

#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>

enum pf_mode { pf_pause, pf_cls };
enum rec_st { st_normal, st_deleted };
enum ins_mode { in_before, in_after };

struct rec_base
{
	char name[40];
	char continent[28];
	char capital[40];
	float area;
	float population;
};

char* Rus(const char* text);
void pause_final(pf_mode mode);
void input_rec(int);
int read_rec(FILE* base, unsigned int pos);
void write_rec(FILE* base, unsigned int pos, rec_base* rea);
void print_head();
void print_separator();
void print_tab_str(rec_base* rea, int pos);
void print_end();
unsigned int get_rec_count(FILE* base);
int remote_reset(FILE* &base);
void remote_repair(FILE* &base);
int insert_record(FILE* base, rec_base* rea, unsigned ins_pos, ins_mode mode);


const int RECORD_S = sizeof(rec_base);
rec_base** inp_1;
rec_base* inp_zap;
void main(void)
{
	int count = 0;
	int var;
	int var_ch = -1;
	int read_c;
	FILE* base;
	int i = 0;
	int priz_vvod = 1;
	int rea;

	inp_1 = (rec_base**)calloc(1, sizeof(rec_base*));

	base = fopen("base.dat", "r+b");
	if (base == NULL)
	{
		base = fopen("base.dat", "w+b");
		fclose(base);
		base = fopen("base.dat", "r+b");
		printf(Rus("База данных создана.Записей в ней нет.\n"));
		printf(Rus("Для продолжения-ENTER.\n"));
		getch();
		system("cls");
	}
	else
	{
		read_c = read_rec(base, i);
		if (read_c)
			printf(Rus("База данных уже существует.В ней имеются записи.\n"));
		else
		{
			printf(Rus("База данных уже существует.Записей в ней нет.\n"));
			printf(Rus("Для продолжения-ENTER.\n"));
			getch();
			system("cls");
		}
	}
	do
	{
		printf(Rus("Выберите пункт меню работы программы:\n"));
		printf(Rus("\n1) Ввод информации в базу данных."));
		printf(Rus("\n2) Корректировка содержимого файла"));
		printf(Rus("\n3) Просмотр записей"));
		printf(Rus("\n4) Выборка по названию страны"));
		printf(Rus("\n5) Завершение работы\n"));

		scanf("%d", &var);
		switch (var)
		{
		case 1:         //ввод информации
		{
			fseek(base, 0, SEEK_END);
			count++;
			input_rec(count);
			while (priz_vvod == 1)
			{
				printf(Rus("Будете ещё вводить информацию?:\n"));
				printf(Rus("Да-1, Нет-0:\n"));
				scanf("%d", &priz_vvod);
				if (priz_vvod == 1)
				{
					count++;
					input_rec(count);
				}
			}
			for (i = 0; i<count; i++)
				fwrite(inp_1[i], RECORD_S, 1, base);
			fflush(base);
			for (i = 0; i<count; i++)
				free(inp_1[i]);
			//free(inp_1);
		}
		break;
		case 2:         //корректировка содержимого
		{
			do
			{
				printf(Rus("Выберите требуемый вариант пункта подменю:\n"
					"\n1) Редактирование указанной записи;"
					"\n2) Пометка записи на удаление (логическое удаление)"
					"\n3) Удаление записей с диска (физическое удаление)"
					"\n4) Восстановление записей (логически удаленных)"
					"\n5) Вставка записи в начало файла"
					"\n6) Вставка после (перед) указанной записью"
					"\n7) Возврат в предыдущее меню\n"));

				scanf("%d", &var_ch);
				switch (var_ch)
				{
				case 1:
				{
					int pos;
					printf(Rus("Введите позицию редактируемой записи:\n"));
					scanf("%d", &pos);

					if (pos>0 && pos <= get_rec_count(base))
					{
						read_c = read_rec(base, pos - 1);
						if (inp_zap->name[0] != '#')
						{
							printf(Rus("Выбранная запись:\n"));
							print_head();
							print_separator();
							print_tab_str(inp_zap, pos);
							free(inp_zap); //освобождение после удачного чтения														
							print_end();
							input_rec(1);
							write_rec(base, pos - 1, inp_1[0]);
						}
						else
							printf(Rus("Выбранная запись не может быть отредактирована, т.к. помечена на удаление.\n"));
					}
					else
						printf(Rus("Ошибка: некорректный ввод позиции"));
				}
				break;
				case 2:
				{
					int pos;
					char buf[40];
					printf(Rus("Введите позицию записи которую желаете пометить на удаление:\n"));
					scanf("%d", &pos);

					if (pos>0 && pos <= get_rec_count(base))
					{
						read_c = read_rec(base, pos - 1);
						if (inp_zap->name[0] != '#')
						{
							printf(Rus("Выбранная запись:\n"));
							print_head();
							print_separator();
							print_tab_str(inp_zap, pos);
							print_end();
							//добавлям в начало имени зарезерированный символ # для отметки о логическом удалении
							strcpy(buf, inp_zap->name);
							inp_zap->name[0] = '#';
							strcpy(inp_zap->name + 1, buf);
							//запись в файл
							write_rec(base, pos - 1, inp_zap);
							printf(Rus("\nЛогическое удаление успешно проведено."));
						}
						else
							printf(Rus("Выбранная запись не может быть удалена, т.к. помечена на удаление.\n"));
						free(inp_zap); //освобождение
					}
					else
						printf(Rus("Ошибка: некорректный ввод позиции"));
				}
				break;
				case 3:
				{
					printf(Rus("\nВы уверены, что хотите >>>>ФИЗИЧЕСКИ УДАЛИТЬ<<<< помеченные записи? (y - да; n - нет)\n"));
					getchar();
					char j = getchar();
					if (j == 89 || j == 121)
					{
						if (remote_reset(base))
							printf(Rus("\nФизическое удаление записей успешно завершено.\n"));
						else
							printf(Rus("\nНа каком-то этапе работы с файлом произошел сбой.\n"));
					}
				}
				break;
				case 4:
				{
					remote_repair(base);
					printf(Rus("\nВосстановление помеченных к удалению записей произведено\n"));
				}
				break;
				case 5:
				{
					input_rec(1);
					if (insert_record(base, inp_1[0], 0, in_before))
						printf(Rus("\nВставка записи в начало файла произведена успешно.\n"));
					else
						printf(Rus("На каком-то этапе работы с файлом произошел сбой.\n"));
				}
				break;
				case 6:
				{
					int pos;
					printf(Rus("Введите позицию записи возле которой желаете произвести вставку новой записи:\n"));
					scanf("%d", &pos);
					if (pos>0 && pos <= get_rec_count(base))
					{
						ins_mode mode = in_before;
						printf(Rus("Введите режим вставки ('0'-перед записью; 1-после):\n"));
						scanf("%d", &mode);
						if (mode == in_before || mode == in_after)
						{
							input_rec(1);
							if (insert_record(base, inp_1[0], pos - 1, mode))
								printf(Rus("\nВставка записи произведена успешно.\n"));
							else
								printf(Rus("\nНа каком-то этапе работы с файлом произошел сбой.\n"));
						}
						else
							printf(Rus("Ошибка: некорректный ввод режима вставки"));
					}
					else
						printf(Rus("Ошибка: некорректный ввод позиции"));
				}
				break;


				case 7:
					break;

				default:
					printf(Rus("Ошибка: некорректный ввод варианта работы"));
				}
				if (var_ch != 7)
					pause_final(pf_pause);
				else
					pause_final(pf_cls);
			} while (var_ch != 7);
			var_ch = -1;
		}
		break;
		case 3:
		{	                                        //просмотр записей
			do
			{
				printf(Rus("Выберите вариант работы подпрограммы:\n"
					"\nПросмотр записей ..."
					"\n1) ...всего файла"
					"\n2) ...с указанной записи и до начала файла"
					"\n3) ...с указанной записи и до конца файла"
					"\n4) Возврат в предыдущее меню\n"));

				scanf("%d", &var_ch);
				switch (var_ch)
				{
				case 1:
				{
					print_head();
					print_separator();
					i = 0;
					rea = read_rec(base, i);
					while (rea)
					{
						print_tab_str(inp_zap, i + 1);
						i++;
						free(inp_zap);
						rea = read_rec(base, i);
						if (rea)
							print_separator();
						if (i % 5 == 0)
						{
							printf(Rus("\nДля продолжения-ENTER\n"));
							getch();
						}
					}
					print_end();
				}
				break;
				case 2:
				{
					int pos;
					printf(Rus("Введите позицию:\n"));
					scanf("%d", &pos);

					if (pos>0 && pos <= get_rec_count(base))
					{
						print_head();
						print_separator();

						for (i = 0; i<pos; i++)
						{
							read_c = read_rec(base, i);
							print_tab_str(inp_zap, i + 1);
							free(inp_zap); //освобождение после удачного чтения														
							if (i<pos - 1)
								print_separator();
						}
						print_end();
					}
					else
						printf(Rus("Ошибка: некорректный ввод позиции"));
				}
				break;
				case 3:
				{
					int pos;
					printf(Rus("Введите позицию:\n"));
					scanf("%d", &pos);

					int rec_count = get_rec_count(base);
					if (pos>0 && pos <= rec_count)
					{
						print_head();
						print_separator();

						for (i = pos - 1; i<rec_count; i++)
						{
							read_c = read_rec(base, i);
							print_tab_str(inp_zap, i + 1);
							free(inp_zap); //освобождение после удачного чтения														
							if (i<rec_count)
								print_separator();
						}
						print_end();
					}
					else
						printf(Rus("Ошибка: некорректный ввод позиции"));
				}
				break;
				case 4:
					break;
				default:
					printf(Rus("Ошибка: некорректный ввод варианта работы"));
				}
				if (var_ch != 4)
					pause_final(pf_pause);
				else
					pause_final(pf_cls);
			} while (var_ch != 4);
			var_ch = -1;
		}
		break;
		case 4: //поиск информации
		{
			var_ch = 4;

			char s[40];
			printf(Rus("Введите страну как фильтр:\n"));
			getchar();
			gets_s(s);

			unsigned int count_r = get_rec_count(base);

			print_head();
			print_separator();

			for (i = 0; i<count_r; i++)
			{
				read_c = read_rec(base, i);
				if (!strcmp(s, inp_zap->name))
				{
					print_tab_str(inp_zap, i + 1);
					free(inp_zap);
					break;
				}
				free(inp_zap);                               //освобождение после удачного чтения														
			}
			print_end();
		}
		break;
		case 5:
			break;
		default:
		{
			printf(Rus("Ошибка: некорректный ввод варианта работы"));
			pause_final(pf_pause);
		}
		}
		if (var != 5 && var_ch != -1)
			pause_final(pf_pause);
		else
			pause_final(pf_cls);
	} while (var != 5);
	fclose(base);
}

int insert_record(FILE* base, rec_base* rea, unsigned ins_pos, ins_mode mode)
{
	FILE* base_n;
	unsigned rc;
	int read_c;
	int res;
	int i;

	rc = get_rec_count(base);
	base_n = fopen("base_n.dat", "a+b");
	fseek(base_n, 0, SEEK_SET);

	if (ins_pos == (rc - 1) && mode) // часный случай - вставка в конец файла
	{
		fseek(base, 0, SEEK_END);
		res = fwrite(rea, RECORD_S, 1, base);
		fflush(base);
		return(res);
	}
	else // общий случай
	{
		fseek(base, 0, SEEK_SET);
		for (i = 0; (!mode && (i<ins_pos)) || (mode && (i <= ins_pos)); i++)
		{
			read_c = read_rec(base, i);
			fwrite(inp_zap, RECORD_S, 1, base_n);
			free(inp_zap);
		}
		fwrite(rea, RECORD_S, 1, base_n);
		for ((!mode) ? i = ins_pos : i = ins_pos + 1; i < rc; i++)
		{
			read_c = read_rec(base, i);
			fwrite(inp_zap, RECORD_S, 1, base_n);
			free(inp_zap);
		}
		fflush(base_n);
		fclose(base_n);
		fflush(base);
		fclose(base);
		return((!remove("base.dat")) && (!rename("base_n.dat", "base.dat")) && ((base = fopen("base.dat", "r+b")) != NULL));
	}
}

void remote_repair(FILE* &base)
{
	unsigned rc;
	int i;
	char buf[40];
	int read_c;
	//rec_base* rea;

	rc = get_rec_count(base);
	fseek(base, 0, SEEK_SET);
	//rea=(rec_base*)calloc(1,RECORD_S);
	for (i = 0; i<rc; i++)
	{
		read_c = read_rec(base, i);
		if (inp_zap->name[0] == '#')
		{
			strcpy(buf, inp_zap->name + 1);
			strcpy(inp_zap->name, buf);
			write_rec(base, i, inp_zap);
		}
		free(inp_zap);
	}
	fflush(base);
}

int remote_reset(FILE* &base)
{
	FILE* base_n;
	rec_base* rea;
	int read_c;

	base_n = fopen("base_n.dat", "a+b");
	fseek(base_n, 0, SEEK_SET);
	fseek(base, 0, SEEK_SET);

	rea = (rec_base*)calloc(1, RECORD_S);
	read_c = fread(rea, RECORD_S, 1, base);
	while (read_c && !feof(base))
	{
		if (rea->name[0] != '#')
			fwrite(rea, RECORD_S, 1, base_n);
		read_c = fread(rea, RECORD_S, 1, base);
	}
	fflush(base_n);
	fclose(base_n);
	fflush(base);
	fclose(base);
	return((!remove("base.dat")) && (!rename("base_n.dat", "base.dat")) && ((base = fopen("base.dat", "r+b")) != NULL));
}

void input_rec(int count_rec)
{
	short err;
	int i = 0;
	if (count_rec == 1)
	{
		inp_1[i] = (rec_base*)calloc(1, RECORD_S);
	}
	else
	{
		i = count_rec - 1;
		inp_1[i] = (rec_base*)calloc(1, RECORD_S);
	}

	if (inp_1[i])
	{
		printf(Rus("\nВведите название страны:\n"));
		getchar();
		gets_s(inp_1[i]->name);
		printf(Rus("Введите название континента:\n"));
		gets_s(inp_1[i]->continent);
		printf(Rus("Введите название столицы:\n"));
		gets_s(inp_1[i]->capital);
		do
		{
			printf(Rus("Введите площадь (тыс. кв. км.):\n"));
			scanf("%f", &(inp_1[i]->area));
			printf(Rus("Введите численность населения (млн. чел.):\n"));
			scanf("%f", &(inp_1[i]->population));
			err = inp_1[i]->area <= 0 || inp_1[i]->population <= 0;
			if (err)
			{
				printf(Rus("\nОшибка: обычно, площадь и население не могут быть равными и меньшими нулю.\n"
					"Попробуйте переввести данные о площади и населении.\n\n"));
				system("pause");
			}
		} while (err);
	}
	else
		printf("Нет возможности перевыделить память\n");
}

void print_head()
{
	printf("\xC9\xCD\xCD\xCD\xCB"
		"\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB"
		"\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB"
		"\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\xBA \xFC \xBA                 "); printf(Rus("Информация")); printf("                \xBA");
	printf("  "); printf(Rus("Площадь")); printf("  \xBA");
	printf(" "); printf(Rus("Население")); printf(" \xBA");
}

void print_separator()
{
	printf("\n\xCC\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE"
		"\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE"
		"\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9");
}

int read_rec(FILE* base, unsigned int pos)
{
	int read_c;
	//отсчет pos с нуля
	fseek(base, RECORD_S*pos, SEEK_SET);
	inp_zap = (rec_base*)calloc(1, RECORD_S);
	read_c = fread(inp_zap, RECORD_S, 1, base);

	if (read_c)
	{
		return(read_c);
	}
	else//освобождение памяти после неудачного чтения
	{
		free(inp_zap);
		return(read_c);
	}
}

void write_rec(FILE* base, unsigned int pos, rec_base* rea)
{
	long cur_pos = ftell(base);
	fseek(base, RECORD_S * pos, SEEK_SET);
	int write_c = fwrite(rea, RECORD_S, 1, base);
	if (write_c != 1)
		printf(Rus("\nЧет не все записалось...\n"));
	else
		fflush(base);
	fseek(base, cur_pos, SEEK_SET);
}


void print_tab_str(rec_base* buffer_basa, int pos)
{
	printf("\n\xBA%3d\xBA", pos);
	(buffer_basa->name[0] == '#') ? printf(Rus("Страна: % 35s"), buffer_basa->name + 1) : printf(Rus("Страна: % 35s"), buffer_basa->name);
	//printf(Rus("Страна: % 35s"), buffer_basa->name);
	printf("\xBA           \xBA           \xBA");
	printf("\n\xBA   \xBA");
	printf(Rus("Континент: %32s"), buffer_basa->continent);
	printf("\xBA%11.3f\xBA%11.3f\xBA", buffer_basa->area, buffer_basa->population);
	printf("\n\xBA");
	(buffer_basa->name[0] == '#') ? printf("DEL") : printf("   ");
	//printf("   ");
	printf("\xBA");
	printf(Rus("Столица: %34s"), buffer_basa->capital);
	printf("\xBA           \xBA           \xBA");
	/*
	printf("\n\xBA%3d\xBA", pos);
	(rea->name[0]=='#')?printf(Rus("Страна: % 35s"),rea->name+1):printf(Rus("Страна: % 35s"),rea->name);
	printf("\xBA           \xBA           \xBA");
	printf("\n\xBA   \xBA");
	printf(Rus("Континент: %32s"), rea->continent);
	printf("\xBA%11.3f\xBA%11.3f\xBA", rea->area, rea->population);
	printf("\n\xBA");
	(rea->name[0]=='#')?printf("DEL"):printf("   ");
	printf("\xBA");
	printf(Rus("Столица: %34s"),rea->capital);
	printf("\xBA           \xBA           \xBA");

	*/
}

unsigned int get_rec_count(FILE* base)
{
	long cur_pos = ftell(base);
	fseek(base, 0, SEEK_END);
	long count_r = ftell(base) / RECORD_S;
	fseek(base, cur_pos, SEEK_SET);
	return(count_r);
}

void print_end()
{
	printf("\n\xC8\xCD\xCD\xCD\xCA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA"
		"\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA"
		"\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
}

void pause_final(pf_mode mode)
{
	if (!mode)
	{
		printf("\n");
		system("pause");
	}
	system("cls");
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}