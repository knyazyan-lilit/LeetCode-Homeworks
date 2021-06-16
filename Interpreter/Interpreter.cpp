#include "Interpreter.h"

    bool Interpreter::is_number(const std::string& s)
	{
		return !s.empty() && std::find_if(s.begin(),
			s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
	}

	void Interpreter::VariableDecl(std::string* str) {



		decmap[str[1]] = { obj.name = str[1] };


	}

	Typedetect Interpreter::Sum(std::string* str, int k)
	{
		

		if (vars.count(str[k + 2]) == 1) {
			if (vars.count(str[k + 4]) == 1)
			{
				if (vars[str[k + 2]].typ == INT && vars[str[k + 4]].typ == INT) {
					int val = *(int*)vars[str[k + 2]].value + *(int*)vars[str[k + 4]].value;
					return { new int(val),INT };

				}
				else if (vars[str[k + 2]].typ == string && vars[str[k + 4]].typ == string) {
					std::string val = *(std::string*)(vars[str[k + 2]].value) + *(std::string*)(vars[str[k + 4]].value);
					return { new std::string(val),string };
				}

			}
			else {

				if (vars[str[k + 2]].typ == INT) {
					if (is_number(str[k + 4])) {
						int val = *((int*)(vars[str[k + 2]].value)) + std::stoi(str[k + 4]);

						return { new int(val),INT };

					}
				}
				else {
					if (!is_number(str[k + 4])) {
						std::string val = *(std::string*)vars[str[k + 2]].value + str[k + 4];
						return { new std::string(val),string };
					}
				}

			}
		}
		else {
			if (vars.count(str[k + 4]) == 1)
			{
				if (is_number(str[k + 2])) {
					if (vars[str[k + 4]].typ == INT) {
						int val = std::stoi(str[k + 2]) + *(int*)vars[str[k + 4]].value;
						return { new int(val),INT };
					}
				}
				else
				{
					if (vars[str[k + 4]].typ == string) {
						std::string val = str[k + 2] + *(std::string*)vars[str[k + 4]].value;

						return { new std::string(val),string };

					}
				}
			}
			else {

				if (is_number(str[k + 2]) && is_number(str[k + 4])) {
					int val = std::stoi(str[k + 2]) + std::stoi(str[k + 4]);
					return { new int(val),INT };

				}

				else {
					std::string val = str[k + 2] + str[k + 4];

					return { new std::string(val),string };
				}
			}
		}
	}

	Typedetect Interpreter::Subtract(std::string* str, int k)
	{

		if (vars.count(str[k + 2]) == 1) {
			if (vars.count(str[k + 4]) == 1)
			{
				if (vars[str[k + 2]].typ == INT && vars[str[k + 4]].typ == INT) {
					int val = *(int*)vars[str[k + 2]].value - *(int*)vars[str[k + 4]].value;
					return { new int(val),INT };

				}


			}
			else if (vars.count(str[k + 4]) == 0 && decmap.count(str[k + 4]) == 1) {

				std::cout << str[4] << " variable is not initialized " << std::endl;
				exit(EXIT_FAILURE);
			}
			else {

				if (vars[str[k + 2]].typ == INT) {
					if (is_number(str[k + 4])) {
						int val = *((int*)(vars[str[k + 2]].value)) - std::stoi(str[k + 4]);

						return { new int(val),INT };

					}
				}


			}
		}

		else if (vars.count(str[k + 2]) == 0 && decmap.count(str[k + 2]) == 1) {

			std::cout<< str[2] << " variable is not initialized " << std::endl;
			exit(EXIT_FAILURE);
		}

		else {
			if (vars.count(str[k + 4]) == 1)
			{
				if (is_number(str[k + 2])) {
					if (vars[str[k + 4]].typ == INT) {
						int val = std::stoi(str[k + 2]) - *(int*)vars[str[k + 4]].value;
						return { new int(val),INT };
					}
				}

			}

			else if (vars.count(str[k + 4]) == 0 && decmap.count(str[k + 4]) == 1) {

				std::cout<< str[4] << " variable is not initialized " << std::endl;
				exit(EXIT_FAILURE);
			}
			else {

				if (is_number(str[k + 2]) && is_number(str[k + 4])) {
					int val = std::stoi(str[k + 2]) - std::stoi(str[k + 4]);
					return { new int(val),INT };

				}


			}
		}
	}

	Typedetect Interpreter::Multiplication(std::string* str, int k)
	{

		if (vars.count(str[k + 2]) == 1) {
			if (vars.count(str[k + 4]) == 1)
			{
				if (vars[str[k + 2]].typ == INT && vars[str[k + 4]].typ == INT) {
					int val = *(int*)vars[str[k + 2]].value * *(int*)vars[str[k + 4]].value;
					return { new int(val),INT };

				}


			}
			else if (vars.count(str[k + 4]) == 0 && decmap.count(str[k + 4]) == 1) {

				std::cout<< str[4] << " variable is not initialized " << std::endl;
				exit(EXIT_FAILURE);
			}
			else {

				if (vars[str[k + 2]].typ == INT) {
					if (is_number(str[k + 4])) {
						int val = *((int*)(vars[str[k + 2]].value)) * std::stoi(str[k + 4]);

						return { new int(val),INT };

					}
				}


			}
		}
		else if (vars.count(str[k + 2]) == 0 && decmap.count(str[k + 2]) == 1) {

			std::cout<< str[2] << " variable is not initialized " << std::endl;
			exit(EXIT_FAILURE);
		}
		else {
			if (vars.count(str[k + 4]) == 1)
			{
				if (is_number(str[k + 2])) {
					if (vars[str[k + 4]].typ == INT) {
						int val = std::stoi(str[k + 2]) * *(int*)vars[str[k + 4]].value;
						return { new int(val),INT };
					}
				}

			}
			else if (vars.count(str[k + 4]) == 0 && decmap.count(str[k + 4]) == 1) {

				std::cout<< str[2] << " variable is not initialized " << std::endl;
				exit(EXIT_FAILURE);
			}
			else {

				if (is_number(str[k + 2]) && is_number(str[k + 4])) {
					int val = std::stoi(str[k + 2]) * std::stoi(str[k + 4]);
					return { new int(val),INT };

				}


			}
		}
	}

	Typedetect Interpreter::QuotientDivision(std::string* str, int k)
	{

		if (vars.count(str[k + 2]) == 1) {
			if (vars.count(str[k + 4]) == 1)
			{
				if (vars[str[k + 2]].typ == INT && vars[str[k + 4]].typ == INT) {
					int val = *(int*)vars[str[k + 2]].value / *(int*)vars[str[k + 4]].value;
					return { new int(val),INT };

				}


			}

			else if (vars.count(str[k + 4]) == 0 && decmap.count(str[k + 4]) == 1) {

				std::cout<< str[4] << " variable is not initialized " << std::endl;
				exit(EXIT_FAILURE);
			}
			else {

				if (vars[str[k + 2]].typ == INT) {
					if (is_number(str[k + 4])) {
						int val = *((int*)(vars[str[k + 2]].value)) / std::stoi(str[k + 4]);

						return { new int(val),INT };

					}
				}


			}
		}

		else if (vars.count(str[k + 2]) == 0 && decmap.count(str[k + 2]) == 1) {

			std::cout<< str[2] << " variable is not initialized " << std::endl;
			exit(EXIT_FAILURE);
		}
		else {
			if (vars.count(str[k + 4]) == 1)
			{
				if (is_number(str[k + 2])) {
					if (vars[str[k + 4]].typ == INT) {
						int val = std::stoi(str[k + 2]) / *(int*)vars[str[k + 4]].value;
						return { new int(val),INT };
					}
				}

			}
			else if (vars.count(str[k + 4]) == 0 && decmap.count(str[k + 4]) == 1) {

				std::cout<< str[4] << " variable is not initialized " << std::endl;
				exit(EXIT_FAILURE);
			}
			else {

				if (is_number(str[k + 2]) && is_number(str[k + 4])) {
					int val = std::stoi(str[k + 2]) / std::stoi(str[k + 4]);
					return { new int(val),INT };

				}


			}
		}
	}

	Typedetect Interpreter::RemainderDivision(std::string* str, int k)
	{
		if (vars.count(str[k + 2]) == 1) {
			if (vars.count(str[k + 4]) == 1)
			{
				if (vars[str[k + 2]].typ == INT && vars[str[k + 4]].typ == INT) {
					int val = *(int*)vars[str[k + 2]].value % *(int*)vars[str[k + 4]].value;
					return { new int(val),INT };

				}


			}
			else if (vars.count(str[k + 4]) == 0 && decmap.count(str[k + 4]) == 1) {

				std::cout<< str[4] << " variable is not initialized " << std::endl;
				exit(EXIT_FAILURE);
			}
			else {

				if (vars[str[k + 2]].typ == INT) {
					if (is_number(str[k + 4])) {
						int val = *((int*)(vars[str[k + 2]].value)) % std::stoi(str[k + 4]);

						return { new int(val),INT };

					}
				}


			}
		}
		else if (vars.count(str[k + 2]) == 0 && decmap.count(str[k + 2]) == 1) {

			std::cout<< str[2] << " variable is not initialized " << std::endl;
			exit(EXIT_FAILURE);
		}
		else {
			if (vars.count(str[k + 4]) == 1)
			{
				if (is_number(str[k + 2])) {
					if (vars[str[k + 4]].typ == INT) {
						int val = std::stoi(str[k + 2]) % *(int*)vars[str[k + 4]].value;
						return { new int(val),INT };
					}
				}

			}
			else if (vars.count(str[k + 4]) == 0 && decmap.count(str[k + 4]) == 1) {

				std::cout<< str[4] << " variable is not initialized " << std::endl;
				exit(EXIT_FAILURE);
			}
			else {

				if (is_number(str[k + 2]) && is_number(str[k + 4])) {
					int val = std::stoi(str[k + 2]) % std::stoi(str[k + 4]);
					return { new int(val),INT };

				}


			}
		}
	}

	void  Interpreter::Assignment(std::string* str) {
		if (decmap.count(str[2])==1) {
			if (vars.count(str[2]) == 1)
			{

				if (str[4] == "sum" || str[4] == "sub" || str[4] == "mul" || str[4] == "quot" || str[4] == "rem")
				{

					int k = 4;

					if (str[4] == "sum") {
						if (vars[str[2]].typ == INT && Sum(str, k).typ == INT) {
							vars[str[2]] = Sum(str, k);
						}

						else if (vars[str[2]].typ == string && Sum(str, k).typ == string) {
							vars[str[2]] = Sum(str, k);
						}

						else {
							std::cout<< " inappropriate types" << std::endl;
							exit(EXIT_FAILURE);
						}

					}
					if (str[4] == "sub") {
						if (vars[str[2]].typ == INT && Subtract(str, k).typ == INT) {
							vars[str[2]] = Subtract(str, k);
						}

						else if (vars[str[2]].typ == string && Subtract(str, k).typ == string) {
							vars[str[2]] = Subtract(str, k);
						}

						else {
							std::cout<< " inappropriate types" << std::endl;
							exit(EXIT_FAILURE);
						}
					}
					else if (str[4] == "mul") {

						if (vars[str[2]].typ == INT && Multiplication(str, k).typ == INT) {
							vars[str[2]] = Multiplication(str, k);
						}

						else {
							std::cout<< " inappropriate types" << std::endl;
							exit(EXIT_FAILURE);
						}
					}

					else if (str[4] == "quot") {
						if (vars[str[2]].typ == INT && QuotientDivision(str, k).typ == INT) {
							vars[str[2]] = QuotientDivision(str, k);
						}

						else {
							std::cout<< " inappropriate types" << std::endl;
							exit(EXIT_FAILURE);
						}
					}

					else if (str[4]=="rem") {
						if (vars[str[2]].typ == INT && RemainderDivision(str, k).typ == INT) {
							vars[str[2]] = RemainderDivision(str, k);
						}

						else {
							std::cout<< " inappropriate types" << std::endl;
							exit(EXIT_FAILURE);
						}
					}
				}


				else
				{
					if (decmap.count(str[4]) == 0) {
						if (vars[str[2]].typ == INT && is_number(str[4])) {

							vars[str[2]] = Typedetect{ new int((std::stoi)(str[4])),INT };


						}

						else if (vars[str[2]].typ == string && is_number(str[4]))
						{

							vars[str[2]] = Typedetect{ new std::string(str[4]),string };
						}
						else {
							std::cout<< "inappropriate types" << std::endl;;
							exit(EXIT_FAILURE);
						}
					}


					else {
						if (vars.count(str[4]) == 0) {
							std::cout<< str[4] << " vavariable is not initialized" << std::endl;;
							exit(EXIT_FAILURE);
						}
						else {
							if (vars[str[2]].typ == INT && vars[str[4]].typ == INT) {

								vars[str[2]] = vars[str[4]];
							}
							else if (vars[str[2]].typ == string && vars[str[4]].typ == string) {
								vars[str[2]] = vars[str[4]];
							}
							else {
								std::cout<< "inappropriate types" << std::endl;;
								exit(EXIT_FAILURE);
							}
						}

					}


				}
			}
			
			else {
				if (str[4] == "sum" || str[4] == "sub" || str[4] == "mul" || str[4] == "quot" || str[4] == "rem")
				{

					int k = 4;

					if (str[4] == "sum") {
						if ( Sum(str, k).typ == INT) {
							vars[str[2]] = { new int(*(int*)Sum(str, k).value), INT };
						}

						else if ( Sum(str, k).typ == string) {
							vars[str[2]] = { new std::string(*(std::string*)Sum(str, k).value), string };
						}

					}
			       else if (str[4] == "sub") {
						if (Subtract(str, k).typ == INT) {
							vars[str[2]] = { new int(*(int*)Subtract(str, k).value), INT };
						}

						else if (Subtract(str, k).typ == string) {
							vars[str[2]] = { new std::string(*(std::string*)Subtract(str, k).value), string };
						}

			       }
					else if (str[4] == "mul") {

						if (Multiplication(str, k).typ == INT) {
							vars[str[2]] = { new int(*(int*)Multiplication(str, k).value), INT };
						}
					}

					else if (str[4] == "quot") {
						if (QuotientDivision(str, k).typ == INT) {
							vars[str[2]] = { new int(*(int*)QuotientDivision(str, k).value), INT };
						}

					
					}

					else {
						if (RemainderDivision(str, k).typ == INT) {
							vars[str[2]] = { new int(*(int*)RemainderDivision(str, k).value), INT };
						}
					}
				}


				else {
					if (vars.count(str[4]) == 1) {
						vars[str[2]] = vars[str[4]];
					}

					else if (vars.count(str[4]) == 0) {
						if (is_number(str[4])) {

							vars[str[2]] = { new int(std::stoi(str[4])),INT };
						}
						else {
							vars[str[2]] = { new std::string(str[4]),string };
						}
					}
					else {
						std::cout<< str[2] << " and " << str[4] << " variables are not declared " << std::endl;;
					}
				}
			}

		}
		
		else {
		std::cout<< str[2] << " variable is not declared" << std::endl;;
		exit(EXIT_FAILURE);
		}
	}

	Typedetect Interpreter::Stosum(std::string* str) {


		if (vars.count(str[2])) {
			if (vars.count(str[4])) {
				if (vars[str[2]].typ == INT && vars[str[4]].typ == INT) {
					*(int*)vars[str[2]].value = *(int*)vars[str[2]].value + *(int*)vars[str[4]].value;
					return { new int(*(int*)vars[str[2]].value),INT };

				}
				else if (vars[str[2]].typ == string && vars[str[4]].typ == string) {
					*(std::string*)vars[str[2]].value = *(std::string*)vars[str[2]].value + *(std::string*)vars[str[4]].value;
					return{ new  std::string(*(std::string*)vars[str[2]].value),string };
				}
			}

			else if (decmap.count(str[4]) == 1 && vars.count(str[4]) == 0) {
				std::cout<< str[4] << " variable is not initialized " << std::endl;;
				exit(EXIT_FAILURE);
			}


			else {
				if (vars[str[2]].typ == INT) {
					if (is_number(str[4])) {
						*(int*)vars[str[2]].value = *((int*)(vars[str[2]].value)) + std::stoi(str[4]);
						return { new int(*(int*)vars[str[2]].value),INT };
					}
				}
				else {
					if (!is_number(str[4])) {
						*(std::string*)vars[str[2]].value = *((std::string*)(vars[str[2]].value)) + str[4];
						return { new std::string(*(std::string*)vars[str[2]].value),string };
					}
				}
			}

		}

		else if (decmap.count(str[2]) == 1 && vars.count(str[2]) == 0) {
			std::cout<< str[2] << " variable is not initialized " << std::endl;;
			exit(EXIT_FAILURE);
		}

		else {
			std::cout<< str[2] << " variable is not declared" << std::endl;;
			exit(EXIT_FAILURE);
		}

	}

	Typedetect Interpreter::Stosub(std::string* str) {

		if (vars.count(str[2])) {
			if (vars.count(str[4])) {
				if (vars[str[2]].typ == INT && vars[str[4]].typ == INT) {
					*(int*)vars[str[2]].value = *(int*)vars[str[2]].value - *(int*)vars[str[4]].value;
					return { new int(*(int*)vars[str[2]].value),INT };

				}

			}
			else if (decmap.count(str[4]) == 1 && vars.count(str[4]) == 0) {
				std::cout << str[4] << " variable is not initialized " << std::endl;;
				exit(EXIT_FAILURE);
			}
			else {
				if (vars[str[2]].typ == INT) {
					if (is_number(str[4])) {
						*(int*)vars[str[2]].value = *((int*)(vars[str[2]].value)) - std::stoi(str[4]);
						return { new int(*(int*)vars[str[2]].value),INT };
					}
				}

			}

		}



		else if (decmap.count(str[2]) == 1 && vars.count(str[2]) == 0) {
			std::cout << str[2] << " variable is not initialized " << std::endl;;
			exit(EXIT_FAILURE);
		}

		else {
			std::cout << str[2] << " variable is not declared" << std::endl;;
			exit(EXIT_FAILURE);
		}
	}

	Typedetect Interpreter::Stomul(std::string* str) {
		
			if (vars.count(str[2])) {
				if (vars.count(str[4])) {
					if (vars[str[2]].typ == INT && vars[str[4]].typ == INT) {
						*(int*)vars[str[2]].value = *(int*)vars[str[2]].value * *(int*)vars[str[4]].value;
						return { new int(*(int*)vars[str[2]].value),INT };

					}

				}

				else if (decmap.count(str[4]) == 1 && vars.count(str[4]) == 0) {
					std::cout << str[4] << " variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {
					if (vars[str[2]].typ == INT) {
						if (is_number(str[4])) {
							*(int*)vars[str[2]].value = *((int*)(vars[str[2]].value)) * std::stoi(str[4]);
							return { new int(*(int*)vars[str[2]].value),INT };
						}
					}

				}

			}

		

		else if (decmap.count(str[2]) == 1 && vars.count(str[2]) == 0) {
			std::cout << str[2] << " variable is not initialized " << std::endl;;
			exit(EXIT_FAILURE);
		}

		else {
			std::cout << str[2] << " variable is not declared" << std::endl;;
			exit(EXIT_FAILURE);
		}
	}

	Typedetect Interpreter::Stoquot(std::string* str) {
		
			if (vars.count(str[2])) {
				if (vars.count(str[4])) {
					if (vars[str[2]].typ == INT && vars[str[4]].typ == INT) {
						*(int*)vars[str[2]].value = *(int*)vars[str[2]].value / *(int*)vars[str[4]].value;
						return { new int(*(int*)vars[str[2]].value),INT };

					}

				}
				else if (decmap.count(str[4]) == 1 && vars.count(str[4]) == 0) {
					std::cout << str[4] << " variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {
					if (vars[str[2]].typ == INT) {
						if (is_number(str[4])) {
							*(int*)vars[str[2]].value = *((int*)(vars[str[2]].value)) / std::stoi(str[4]);
							return { new int(*(int*)vars[str[2]].value),INT };
						}
					}

				}

			}


			else if (decmap.count(str[2]) == 1 && vars.count(str[2]) == 0) {
				std::cout << str[2] << " variable is not initialized " << std::endl;;
				exit(EXIT_FAILURE);
			}

			else {
				std::cout << str[2] << " variable is not declared" << std::endl;;
				exit(EXIT_FAILURE);
			}
	}

	Typedetect Interpreter::Storem(std::string* str) {
		
			if (vars.count(str[2])) {
				if (vars.count(str[4])) {
					if (vars[str[2]].typ == INT && vars[str[4]].typ == INT) {
						*(int*)vars[str[2]].value = *(int*)vars[str[2]].value % *(int*)vars[str[4]].value;
						return { new int(*(int*)vars[str[2]].value),INT };

					}

				}

				else if (decmap.count(str[4]) == 1 && vars.count(str[4]) == 0) {
					std::cout << str[4] << " variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {
					if (vars[str[2]].typ == INT) {
						if (is_number(str[4])) {
							*(int*)vars[str[2]].value = *((int*)(vars[str[2]].value)) % std::stoi(str[4]);
							return { new int(*(int*)vars[str[2]].value),INT };
						}
					}

				}

			}

		
			else if (decmap.count(str[2]) == 1 && vars.count(str[2]) == 0) {
				std::cout << str[2] << " variable is not initialized " << std::endl;;
				exit(EXIT_FAILURE);
			}

			else {
				std::cout << str[2] << " variable is not declared" << std::endl;;
				exit(EXIT_FAILURE);
			}
	}

	Typedetect Interpreter::Inc(std::string* str) {
		
			if (vars.count(str[1])) {
				if (vars[str[1]].typ == INT) {
					*(int*)vars[str[1]].value = (*(int*)vars[str[1]].value) ++;
					return { new int(*(int*)vars[str[1]].value),INT };
				}

			}
		
			else if (decmap.count(str[1]) == 1 && vars.count(str[1]) == 0) {
				std::cout << str[1] << " variable is not initialized " << std::endl;;
				exit(EXIT_FAILURE);
			}

			else {
				std::cout << str[1] << " variable is not declared" << std::endl;;
				exit(EXIT_FAILURE);
			}
	}

	Typedetect Interpreter::Dec(std::string* str) {
		
			if (vars.count(str[1])) {
				if (vars[str[1]].typ == INT) {
					*(int*)vars[str[1]].value = *(int*)vars[str[1]].value - 1;
					return { new int(*(int*)vars[str[1]].value),INT };
				}

			}
			else if (decmap.count(str[1]) == 1 && vars.count(str[1]) == 0) {
				std::cout << str[1] << " variable is not initialized " << std::endl;;
				exit(EXIT_FAILURE);
			}

			else {
				std::cout << str[1] << " variable is not declared" << std::endl;;
				exit(EXIT_FAILURE);
			}
	}

	void Interpreter::Printel(std::string* str, int k) {
		k = k + 2;
		
		
		
		if (str[k] == "sum") {
			if (Sum(str, k).typ == INT) {
				std::cout << *(int*)Sum(str, k).value << std::endl;;
			}
			if (Sum(str, k).typ == string) {
				std::cout << *(std::string*)Sum(str, k).value << std::endl;;
			}
		
		}
		else if (str[k] == "sub") {

			if (Subtract(str, k).typ == INT) {
				std::cout << *(int*)Subtract(str, k).value << std::endl;;
			}
			if (Subtract(str, k).typ == string) {
				std::cout << *(std::string*)Subtract(str, k).value << std::endl;;
			}
		}
		else if (str[k] == "mul") {

			if (Multiplication(str, k).typ == INT) {
				std::cout << *(int*)Multiplication(str, k).value << std::endl;;
			}
			if (Multiplication(str, k).typ == string) {
				std::cout << *(std::string*)Multiplication(str, k).value << std::endl;;
			}
		}

		else if (str[k] == "quot") {

			if (QuotientDivision(str, k).typ == INT) {
				std::cout << *(int*)QuotientDivision(str, k).value << std::endl;;
			}
			if (QuotientDivision(str, k).typ == string) {
				std::cout << *(std::string*)QuotientDivision(str, k).value << std::endl;;
			}
		}
		else if (str[k] == "rem") {

			if (RemainderDivision(str, k).typ == INT) {
				std::cout << *(int*)RemainderDivision(str, k).value << std::endl;;
			}
			if (RemainderDivision(str, k).typ == string) {
				std::cout << *(std::string*)RemainderDivision(str, k).value << std::endl;;
			}
		}
		else if (str[k] == "stosum") {

			if (Stosum(str).typ == INT) {
				std::cout << *(int*)Stosum(str).value << std::endl;;
			}
			if (Stosum(str).typ == string) {
				std::cout << *(std::string*)Stosum(str).value << std::endl;;
			}
		}
		else if (str[k] == "stosub") {


			if (Stosub(str).typ == INT) {
				std::cout << *(int*)Stosub(str).value << std::endl;;
			}
			if (Stosub(str).typ == string) {
				std::cout << *(std::string*)Stosub(str).value << std::endl;;
			}
		}
		else if (str[k] == "stomul") {


			if (Stomul(str).typ == INT) {
				std::cout << *(int*)Stomul(str).value << std::endl;;
			}
			if (Stomul(str).typ == string) {
				std::cout << *(std::string*)Stomul(str).value << std::endl;;
			}
		}
		else if (str[k] == "stoquot") {

			if (Stoquot(str).typ == INT) {
				std::cout << *(int*)Stoquot(str).value << std::endl;;
			}
			if (Stoquot(str).typ == string) {
				std::cout << *(std::string*)Stoquot(str).value << std::endl;;
			}
		}
		else if (str[k] == "storem") {


			if (Storem(str).typ == INT) {
				std::cout << *(int*)Storem(str).value << std::endl;;
			}
			if (Storem(str).typ == string) {
				std::cout << *(std::string*)Storem(str).value << std::endl;;
			}
		}
		//ete hajordum e simvol/ner
		else if (decmap.count(str[k]) == 0) {

			if (!is_number(str[k])) {
				while (!is_number(str[k]) && str[k] != ")") {
					
					std::cout << str[k] << " ";
					k++;

				}
				std::cout << std::endl;;
			}
			//ete hajordum e tiv
			else {

				std::cout << std::stoi(str[k]) << std::endl;;

			}

		}

		if (decmap.count(str[k]) == 1) {
			if (vars.count(str[k]) == 1) {
				
				if (vars[str[k]].typ == INT) {
					
					std::cout << *(int*)vars[str[k]].value << std::endl;;
				}
				if (vars[str[k]].typ == string) {
					std::cout << *(std::string*)vars[str[k]].value << std::endl;;
				}
			}
			
		}
		if (decmap.count(str[k]) == 1 && vars.count(str[k]) == 0) {
			std::cout << str[k] << " variable is not initialized" << std::endl;;
			exit(EXIT_FAILURE);
		}

	}
	
	void Interpreter::Helper2(std::string* str,std::fstream& f) {
		std::string newstr[15];
		int k = 0;
		int j = 0;
		std::string l;
		if (str[0] == "check") {
			
			while (l != "endif") {
				f >> l;
				newstr[j] = l;

				j++;

				if (f.peek() == '\n') {
					
					Checking(newstr, k, f);
					for (int m = 0; m < 11; m++) {
						newstr[m].clear();
					}
					j = 0;
				}

			}
		}
		else if (str[0] == "loop") {
			while (l != "end") {
				
				f >> l;
				newstr[j] = l;

				j++;

				if (f.peek() == '\n') {
					
					Checking(newstr, k, f);
					for (int m = 0; m < 15; m++) {
						newstr[m].clear();
					}
					j = 0;
				}

			}
		}


	}

   	void Interpreter::If_Complement1(std::string* str, std::fstream& f) {
		
			if (str[2] == "sum") {
				int k = 2;
				Sum(str, k);

				if (vars.count(str[9]) == 1) {
					if (Sum(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (Sum(str, k).value == vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else if (Sum(str, k).typ == string && vars[str[9]].typ == string) {
						if (Sum(str, k).value == vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}
				else {

					if (Sum(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)Sum(str, k).value) == std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else  if (Sum(str, k).typ == string && !is_number(str[9])) {
						if (*(std::string*)Sum(str, k).value == str[9]) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}


			if (str[2] == "sub") {
				int k = 2;
				Subtract(str, k);

				if (vars.count(str[9]) == 1) {
					if (Subtract(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (Subtract(str, k).value == vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else if (Subtract(str, k).typ == string && vars[str[9]].typ == string) {
						if (Subtract(str, k).value == vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (Subtract(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)Subtract(str, k).value) == std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else  if (Subtract(str, k).typ == string && !is_number(str[9])) {
						if (*(std::string*)Subtract(str, k).value == str[9]) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}


			if (str[2] == "mul") {
				int k = 2;
				Multiplication(str, k);

				if (vars.count(str[9]) == 1) {
					if (Multiplication(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (Multiplication(str, k).value == vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (Multiplication(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)Multiplication(str, k).value) == std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}


			if (str[2] == "quot") {
				int k = 2;
				QuotientDivision(str, k);

				if (vars.count(str[9]) == 1) {
					if (QuotientDivision(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (QuotientDivision(str, k).value == vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (QuotientDivision(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)QuotientDivision(str, k).value) == std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}



			if (str[2] == "rem") {
				
				int k = 2;
				RemainderDivision(str, k);

				if (vars.count(str[9]) == 1) {
					
					if (RemainderDivision(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (RemainderDivision(str, k).value == vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
						
							while (l != "endif") {
								f >> l;

							}
						
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;

						exit(EXIT_FAILURE);
						
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}
				
				else {
					
					if (RemainderDivision(str, k).typ == INT && is_number(str[9])) {
					
						if (*((int*)RemainderDivision(str, k).value) == std::stoi(str[9])) {
							std::string l1;
							f.seekp(std::ios_base::cur);
							while (l1 != "do") {
								f >> l1;
								
							}
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;

						exit(EXIT_FAILURE);
					}
				}
			}
		
	}

	void Interpreter::If_Complement2(std::string* str,std::fstream& f) {
		if (str[8] == "!=") {
			if (str[2] == "sum") {
				int k = 2;
				Sum(str, k);

				if (vars.count(str[9]) == 1) {
					if (Sum(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (Sum(str, k).value != vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else if (Sum(str, k).typ == string && vars[str[9]].typ == string) {
						if (Sum(str, k).value != vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (Sum(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)Sum(str, k).value) != std::stoi(str[9])) {

							
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else  if (Sum(str, k).typ == string && !is_number(str[9])) {
						if (*(std::string*)Sum(str, k).value != str[9]) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}


			if (str[2] == "sub") {
				int k = 2;
				Subtract(str, k);

				if (vars.count(str[9]) == 1) {
					if (Subtract(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (Subtract(str, k).value != vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else if (Subtract(str, k).typ == string && vars[str[9]].typ == string) {
						if (Subtract(str, k).value != vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (Subtract(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)Subtract(str, k).value) != std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else  if (Subtract(str, k).typ == string && !is_number(str[9])) {
						if (*(std::string*)Subtract(str, k).value != str[9]) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}
		

			if (str[2] == "mul") {
				int k = 2;
				Multiplication(str, k);

				if (vars.count(str[9]) == 1) {
					if (Multiplication(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (Multiplication(str, k).value != vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (Multiplication(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)Multiplication(str, k).value) != std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}




			if (str[2] == "quot") {
				int k = 2;
				QuotientDivision(str, k);

				if (vars.count(str[9]) == 1) {
					if (QuotientDivision(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (QuotientDivision(str, k).value != vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (QuotientDivision(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)QuotientDivision(str, k).value) != std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}



			if (str[2] == "rem") {
				int k = 2;
				RemainderDivision(str, k);

				if (vars.count(str[9]) == 1) {
					if (RemainderDivision(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (RemainderDivision(str, k).value != vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (RemainderDivision(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)RemainderDivision(str, k).value) != std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}
		}
	}

	void Interpreter::If_Complement3(std::string* str, std::fstream& f) {
		if (str[8] == ">") {
			if (str[2] == "sum") {
				int k = 2;
				Sum(str, k);

				if (vars.count(str[9]) == 1) {
					if (Sum(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (Sum(str, k).value > vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else if (Sum(str, k).typ == string && vars[str[9]].typ ==  string) {
						if (Sum(str, k).value > vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (Sum(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)Sum(str, k).value) > std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else  if (Sum(str, k).typ == string && !is_number(str[9])) {
						if (*(std::string*)Sum(str, k).value > str[9]) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}


			if (str[2] == "sub") {
				int k = 2;
				Subtract(str, k);

				if (vars.count(str[9]) == 1) {
					if (Subtract(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (Subtract(str, k).value > vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else if (Subtract(str, k).typ == string && vars[str[9]].typ == string) {
						if (Subtract(str, k).value > vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (Subtract(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)Subtract(str, k).value) > std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else  if (Subtract(str, k).typ == string && !is_number(str[9])) {
						if (*(std::string*)Subtract(str, k).value > str[9]) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}

		

			if (str[2] == "mul") {
				int k = 2;
				Multiplication(str, k);

				if (vars.count(str[9]) == 1) {
					if (Multiplication(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (Multiplication(str, k).value > vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (Multiplication(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)Multiplication(str, k).value) > std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}


			if (str[2] == "quot") {
				int k = 2;
				QuotientDivision(str, k);

				if (vars.count(str[9]) == 1) {
					if (QuotientDivision(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (QuotientDivision(str, k).value > vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (QuotientDivision(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)QuotientDivision(str, k).value) > std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}

			if (str[2] == "rem") {
				int k = 2;
				RemainderDivision(str, k);

				if (vars.count(str[9]) == 1) {
					if (RemainderDivision(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (RemainderDivision(str, k).value > vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (RemainderDivision(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)RemainderDivision(str, k).value) > std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}
		}
	}

	void Interpreter::If_Complement4(std::string* str, std::fstream& f) {
		if (str[8] == "<") {
			if (str[2] == "sum") {
				int k = 2;
				Sum(str, k);

				if (vars.count(str[9]) == 1) {
					if (Sum(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (Sum(str, k).value < vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else if (Sum(str, k).typ == string && vars[str[9]].typ == string) {
						if (Sum(str, k).value < vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (Sum(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)Sum(str, k).value) < std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else  if (Sum(str, k).typ==string && !is_number(str[9])) {
						if (*(std::string*)Sum(str, k).value < str[9]) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}


			if (str[2] == "sub") {
				int k = 2;
				Subtract(str, k);

				if (vars.count(str[9]) == 1) {
					if (Subtract(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (Subtract(str, k).value < vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else if (Subtract(str, k).typ==string && vars[str[9]].typ==string) {
						if (Subtract(str, k).value < vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (Subtract(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)Subtract(str, k).value) < std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else  if (Subtract(str, k).typ==string && !is_number(str[9])) {
						if (*(std::string*)Subtract(str, k).value < str[9]) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}


			if (str[2] == "mul") {
				int k = 2;
				Multiplication(str, k);

				if (vars.count(str[9]) == 1) {
					if (Multiplication(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (Multiplication(str, k).value < vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (Multiplication(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)Multiplication(str, k).value) < std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}


			if (str[2] == "quot") {
				int k = 2;
				QuotientDivision(str, k);

				if (vars.count(str[9]) == 1) {
					if (QuotientDivision(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (QuotientDivision(str, k).value < vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (QuotientDivision(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)QuotientDivision(str, k).value) < std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}



			if (str[2] == "rem") {
				int k = 2;
				RemainderDivision(str, k);

				if (vars.count(str[9]) == 1) {
					if (RemainderDivision(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (RemainderDivision(str, k).value < vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (RemainderDivision(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)RemainderDivision(str, k).value) < std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}
		}
	}

	void Interpreter::If_Complement5(std::string* str, std::fstream& f) {
		if (str[8] == ">=") {
			if (str[2] == "sum") {
				int k = 2;
				Sum(str, k);

				if (vars.count(str[9]) == 1) {
					if (Sum(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (Sum(str, k).value >= vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else if (Sum(str, k).typ == string && vars[str[9]].typ == string) {
						if (Sum(str, k).value >= vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (Sum(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)Sum(str, k).value) >= std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else  if (Sum(str, k).typ==string && !is_number(str[9])) {
						if (*(std::string*)Sum(str, k).value >= str[9]) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}


			if (str[2] == "sub") {
				int k = 2;
				Subtract(str, k);

				if (vars.count(str[9]) == 1) {
					if (Subtract(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (Subtract(str, k).value >= vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else if (Subtract(str, k).typ == string && vars[str[9]].typ == string) {
						if (Subtract(str, k).value >= vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (Subtract(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)Subtract(str, k).value) >= std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else  if (Subtract(str, k).typ == string && !is_number(str[9])) {
						if (*(std::string*)Subtract(str, k).value >= str[9]) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}


			if (str[2] == "mul") {
				int k = 2;
				Multiplication(str, k);

				if (vars.count(str[9]) == 1) {
					if (Multiplication(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (Multiplication(str, k).value >= vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (Multiplication(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)Multiplication(str, k).value) >= std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}


			if (str[2] == "quot") {
				int k = 2;
				QuotientDivision(str, k);

				if (vars.count(str[9]) == 1) {
					if (QuotientDivision(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (QuotientDivision(str, k).value >= vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (QuotientDivision(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)QuotientDivision(str, k).value) >= std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}



			if (str[2] == "rem") {
				int k = 2;
				RemainderDivision(str, k);

				if (vars.count(str[9]) == 1) {
					if (RemainderDivision(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (RemainderDivision(str, k).value >= vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (RemainderDivision(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)RemainderDivision(str, k).value) >= std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}
		}
	}

	void Interpreter::If_Complement6(std::string* str, std::fstream& f) {
		if (str[8] == "<=") {
			if (str[2] == "sum") {
				int k = 2;
				Sum(str, k);

				if (vars.count(str[9]) == 1) {
					if (Sum(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (Sum(str, k).value <= vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else if (Sum(str, k).typ ==string && vars[str[9]].typ == string) {
						if (Sum(str, k).value <= vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
						
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (Sum(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)Sum(str, k).value) <= std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else  if (Sum(str, k).typ == string && !is_number(str[9])) {
						if (*(std::string*)Sum(str, k).value <= str[9]) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
						
					}
				}
			}


			if (str[2] == "sub") {
				int k = 2;
				Subtract(str, k);

				if (vars.count(str[9]) == 1) {
					if (Subtract(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (Subtract(str, k).value <= vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else if (Subtract(str, k).typ == string && vars[str[9]].typ == string) {
						if (Subtract(str, k).value <= vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);

				}

				else {

					if (Subtract(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)Subtract(str, k).value) <= std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else  if (Subtract(str, k).typ == string && !is_number(str[9])) {
						if (*(std::string*)Subtract(str, k).value <= str[9]) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}


			if (str[2] == "mul") {
				int k = 2;
				Multiplication(str, k);

				if (vars.count(str[9]) == 1) {
					if (Multiplication(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (Multiplication(str, k).value <= vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (Multiplication(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)Multiplication(str, k).value) <= std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}


			if (str[2] == "quot") {
				int k = 2;
				QuotientDivision(str, k);

				if (vars.count(str[9]) == 1) {
					if (QuotientDivision(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (QuotientDivision(str, k).value <= vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (QuotientDivision(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)QuotientDivision(str, k).value) <= std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}



			if (str[2] == "rem") {
				int k = 2;
				RemainderDivision(str, k);

				if (vars.count(str[9]) == 1) {
					if (RemainderDivision(str, k).typ == INT && vars[str[9]].typ == INT) {
						if (RemainderDivision(str, k).value <= vars[str[9]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}

				else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
					std::cout << str[9] << "  variable is not initialized " << std::endl;;
					exit(EXIT_FAILURE);
				}

				else {

					if (RemainderDivision(str, k).typ == INT && is_number(str[9])) {
						if (*((int*)RemainderDivision(str, k).value) <= std::stoi(str[9])) {

							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}

					else {
						std::cout << "inappropriate types" << std::endl;;
						exit(EXIT_FAILURE);
					}
				}
			}
		}
	}

	void Interpreter::Ifststemant(std::string* str, std::fstream& f) {
		
		if (str[3] == "==") {

			if (vars.count(str[2]) == 1) {
				if (vars.count(str[4]) == 0) {
					if (vars[str[2]].typ == INT && is_number(str[4])) {
						if (*(int*)vars[str[2]].value == std::stoi(str[4]))
						{
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}

					}
					else if (vars[str[2]].typ==string && !is_number(str[4])) {
						if (*(std::string*)vars[str[2]].value == str[4])
						{
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
				}
				else {
					if (vars[str[2]].typ == INT && vars[str[4]].typ == INT) {
						if (*(int*)vars[str[2]].value == *(int*)vars[str[4]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else if (vars[str[2]].typ==string && vars[str[4]].typ==string)
					{
						if (*(std::string*)vars[str[2]].value == *(std::string*)vars[str[4]].value) {
							Helper2(str, f);
						}
					}
					else {

						std::string l;
						while (l != "endif") {
							f >> l;

						}
					}
				}

			}
			else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
				std::cout << str[9] << " variable is not initialized " << std::endl;;
				exit(EXIT_FAILURE);
			}
		}



		if (str[3] == ">") {

			if (vars.count(str[2]) == 1) {
				if (vars.count(str[4]) == 0) {
					if (vars[str[2]].typ == INT && is_number(str[4])) {
						if (*(int*)vars[str[2]].value > std::stoi(str[4]))
						{
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}

					}
					else if (vars[str[2]].typ==string && !is_number(str[4])) {
						if (*(std::string*)vars[str[2]].value > str[4])
						{
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
				}
				else {
					if (vars[str[2]].typ == INT && vars[str[4]].typ == INT) {
						if (*(int*)vars[str[2]].value > * (int*)vars[str[4]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else if (vars[str[2]].typ==string && vars[str[4]].typ==string)
					{
						if (*(std::string*)vars[str[2]].value > * (std::string*)vars[str[4]].value) {
							Helper2(str, f);
						}
					}
					else {

						std::string l;
						while (l != "endif") {
							f >> l;

						}
					}
				}

			}
			else if (decmap.count(str[2]) == 1 && vars.count(str[2]) == 0) {
				std::cout << str[2] << "  variable is not initialized " << std::endl;;
			}
		}




		if (str[3] == "<") {

			if (vars.count(str[2]) == 1) {
				if (vars.count(str[4]) == 0) {
					if (vars[str[2]].typ == INT && is_number(str[4])) {
						if (*(int*)vars[str[2]].value < std::stoi(str[4]))
						{
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}

					}
					else if (vars[str[2]].typ==string && !is_number(str[4])) {
						if (*(std::string*)vars[str[2]].value < str[4])
						{
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
				}
				else {
					if (vars[str[2]].typ == INT && vars[str[4]].typ == INT) {
						if (*(int*)vars[str[2]].value < *(int*)vars[str[4]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else if (vars[str[2]].typ==string && vars[str[4]].typ==string)
					{
						if (*(std::string*)vars[str[2]].value < *(std::string*)vars[str[4]].value) {
							Helper2(str, f);
						}
					}
					else {

						std::string l;
						while (l != "endif") {
							f >> l;

						}
					}
				}

			}
			else if (decmap.count(str[2]) == 1 && vars.count(str[2]) == 0) {
				std::cout << str[2] << "  variable is not initialized " << std::endl;;
			}
		}



		if (str[3] == "<=") {
			if (vars.count(str[2]) == 1) {
				if (vars.count(str[4]) == 0) {
					if (vars[str[2]].typ == INT && is_number(str[4])) {
						if (*(int*)vars[str[2]].value <= std::stoi(str[4]))
						{
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}

					}
					else if (vars[str[2]].typ==string && !is_number(str[4])) {
						if (*(std::string*)vars[str[2]].value <= str[4])
						{
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
				}
				else {
					if (vars[str[2]].typ == INT && vars[str[4]].typ == INT) {
						if (*(int*)vars[str[2]].value <= *(int*)vars[str[4]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else if (vars[str[2]].typ==string && vars[str[4]].typ==string)
					{
						if (*(std::string*)vars[str[2]].value <= *(std::string*)vars[str[4]].value) {
							Helper2(str, f);
						}
					}
					else {

						std::string l;
						while (l != "endif") {
							f >> l;

						}
					}
				}

			}
			else if (decmap.count(str[2]) == 1 && vars.count(str[2]) == 0) {
				std::cout << str[2] << "  variable is not initialized " << std::endl;;
			}
		}



		if (str[3] == ">=") {
			if (vars.count(str[2]) == 1) {
				if (vars.count(str[4]) == 0) {
					if (vars[str[2]].typ == INT && is_number(str[4])) {
						if (*(int*)vars[str[2]].value >= std::stoi(str[4]))
						{
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}

					}
					else if (vars[str[2]].typ==string && !is_number(str[4])) {
						if (*(std::string*)vars[str[2]].value >= str[4])
						{
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
				}
				else {
					if (vars[str[2]].typ == INT && vars[str[4]].typ == INT) {
						if (*(int*)vars[str[2]].value >= *(int*)vars[str[4]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else if (vars[str[2]].typ==string && vars[str[4]].typ==string)
					{
						if (*(std::string*)vars[str[2]].value >= *(std::string*)vars[str[4]].value) {
							Helper2(str, f);
						}
					}
					else {

						std::string l;
						while (l != "endif") {
							f >> l;

						}
					}
				}

			}
			else if (decmap.count(str[2]) == 1 && vars.count(str[2]) == 0) {
				std::cout << str[2] << "  variable is not initialized " << std::endl;;
			}
		}



		if (str[3] == "!=") {
			if (vars.count(str[2]) == 1) {
				if (vars.count(str[4]) == 0) {
					if (vars[str[2]].typ == INT && is_number(str[4])) {
						if (*(int*)vars[str[2]].value != std::stoi(str[4]))
						{
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}

					}
					else if (vars[str[2]].typ==string && !is_number(str[4])) {
						if (*(std::string*)vars[str[2]].value != str[4])
						{
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
				}
				else {
					if (vars[str[2]].typ == INT && vars[str[4]].typ == INT) {
						if (*(int*)vars[str[2]].value != *(int*)vars[str[4]].value) {
							Helper2(str, f);
						}
						else {

							std::string l;
							while (l != "endif") {
								f >> l;

							}
						}
					}
					else if (vars[str[2]].typ==string && vars[str[4]].typ==string)
					{
						if (*(std::string*)vars[str[2]].value != *(std::string*)vars[str[4]].value) {
							Helper2(str, f);
						}
					}
					else {

						std::string l;
						while (l != "endif") {
							f >> l;

						}
					}
				}

			}
			else if (decmap.count(str[2]) == 1 && vars.count(str[2]) == 0) {
				std::cout << str[2] << "  variable is not initialized " << std::endl;;
			}
		}


		if (str[8] == "==") {
			If_Complement1(str, f);
		}

		if (str[8] == "!=") {
			If_Complement2(str, f);
		}

		if (str[8] == ">") {
			If_Complement3(str, f);
		}

		if (str[8] == "<") {
			If_Complement4(str, f);
		}

		if (str[8] == ">=") {
			If_Complement5(str, f);
		}

		if (str[8] == "<=") {
			If_Complement6(str, f);
		}

    }

	void Interpreter::Loop(std::string* str, std::fstream& f) {
		
		if (str[3] == "<") {
			if (vars.count(str[2]) == 1) {
				if (vars.count(str[4]) == 0) {
					if (vars[str[2]].typ == INT && is_number(str[4])) {
						if (*(int*)vars[str[2]].value < std::stoi(str[4])) {
						
							while (*(int*)vars[str[2]].value < std::stoi(str[4]))
							{
								
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);

								
							}
						}
						else {

							std::string l;

							while (l != "end") {
								f >> l;

							}

						}
					}

					else if (vars[str[2]].typ==string && !is_number(str[4])) {
						if (*(std::string*)vars[str[2]].value < str[4]) {
							while (*(std::string*)vars[str[2]].value < str[4])
							{
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);

							}
						}
						else {

							std::string l;

							while (l != "end") {
								f >> l;

							}

						}
					}

				}
				else {
					if (vars[str[2]].typ == INT && vars[str[4]].typ == INT) {
						if (*(int*)vars[str[2]].value < *(int*)vars[str[4]].value) {
							while (*(int*)vars[str[2]].value < *(int*)vars[str[4]].value) {
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);
							}
						}
						else {

							std::string l;
							while (l != "end") {
								f >> l;

							}
						}
					}
					else if (vars[str[2]].typ==string && vars[str[4]].typ==string) {
						if (*(std::string*)vars[str[2]].value < *(std::string*)vars[str[4]].value) {
							while (*(std::string*)vars[str[2]].value < *(std::string*)vars[str[4]].value) {
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);
							}
						}
						else {

							std::string l;
							while (l != "end") {
								f >> l;

							}
						}
					}

				}
			}
			else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
			std::cout << str[9] << " variable is not initialized " << std::endl;;
			exit(EXIT_FAILURE);
			}
		}


		if (str[3] == ">") {
			if (vars.count(str[2]) == 1) {
				if (vars.count(str[4]) == 0) {
					if (vars[str[2]].typ == INT && is_number(str[4])) {
						if (*(int*)vars[str[2]].value > std::stoi(str[4])) {
							while (*(int*)vars[str[2]].value > std::stoi(str[4]))
							{
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);

							}
						}
						else {

							std::string l;

							while (l != "end") {
								f >> l;

							}

						}
					}

					else if (vars[str[2]].typ==string && !is_number(str[4])) {
						if (*(std::string*)vars[str[2]].value > str[4]) {
							while (*(std::string*)vars[str[2]].value > str[4])
							{
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);

							}
						}
						else {

							std::string l;

							while (l != "end") {
								f >> l;

							}

						}
					}

				}
				else {
					if (vars[str[2]].typ == INT && vars[str[4]].typ == INT) {
						if (*(int*)vars[str[2]].value > * (int*)vars[str[4]].value) {
							while (*(int*)vars[str[2]].value > * (int*)vars[str[4]].value) {
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);
							}
						}
						else {

							std::string l;
							while (l != "end") {
								f >> l;

							}
						}
					}
					else if (vars[str[2]].typ==string && vars[str[4]].typ==string) {
						if (*(std::string*)vars[str[2]].value > * (std::string*)vars[str[4]].value) {
							while (*(std::string*)vars[str[2]].value > * (std::string*)vars[str[4]].value) {
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);
							}
						}
						else {

							std::string l;
							while (l != "end") {
								f >> l;

							}
						}
					}

				}
			}
			else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
			std::cout << str[9] << " variable is not initialized " << std::endl;;
			exit(EXIT_FAILURE);
			}
		}



		if (str[3] == ">=") {
			if (vars.count(str[2]) == 1) {
				if (vars.count(str[4]) == 0) {
					if (vars[str[2]].typ == INT && is_number(str[4])) {
						if (*(int*)vars[str[2]].value >= std::stoi(str[4])) {
							while (*(int*)vars[str[2]].value >= std::stoi(str[4]))
							{
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);

							}
						}
						else {

							std::string l;

							while (l != "end") {
								f >> l;

							}

						}
					}

					else if (vars[str[2]].typ==string && !is_number(str[4])) {
						if (*(std::string*)vars[str[2]].value >= str[4]) {
							while (*(std::string*)vars[str[2]].value >= str[4])
							{
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);

							}
						}
						else {

							std::string l;

							while (l != "end") {
								f >> l;

							}

						}
					}

				}
				else {
					if (vars[str[2]].typ == INT && vars[str[4]].typ == INT) {
						if (*(int*)vars[str[2]].value >= *(int*)vars[str[4]].value) {
							while (*(int*)vars[str[2]].value >= *(int*)vars[str[4]].value) {
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);
							}
						}
						else {

							std::string l;
							while (l != "end") {
								f >> l;

							}
						}
					}
					else if (vars[str[2]].typ==string && vars[str[4]].typ==string) {
						if (*(std::string*)vars[str[2]].value >= *(std::string*)vars[str[4]].value) {
							while (*(std::string*)vars[str[2]].value >= *(std::string*)vars[str[4]].value) {
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);
							}
						}
						else {

							std::string l;
							while (l != "end") {
								f >> l;

							}
						}
					}

				}
			}
			else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
			std::cout << str[9] << " variable is not initialized " << std::endl;;
			exit(EXIT_FAILURE);
			}
		}

		if (str[3] == "<=") {
			if (vars.count(str[2]) == 1) {
				if (vars.count(str[4]) == 0) {
					if (vars[str[2]].typ == INT && is_number(str[4])) {
						if (*(int*)vars[str[2]].value <= std::stoi(str[4])) {
							while (*(int*)vars[str[2]].value <= std::stoi(str[4]))
							{
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);

							}
						}
						else {

							std::string l;

							while (l != "end") {
								f >> l;

							}

						}
					}

					else if (vars[str[2]].typ==string && !is_number(str[4])) {
						if (*(std::string*)vars[str[2]].value <= str[4]) {
							while (*(std::string*)vars[str[2]].value <= str[4])
							{
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);

							}
						}
						else {

							std::string l;

							while (l != "end") {
								f >> l;

							}

						}
					}

				}
				else {
					if (vars[str[2]].typ == INT && vars[str[4]].typ == INT) {
						if (*(int*)vars[str[2]].value <= *(int*)vars[str[4]].value) {
							while (*(int*)vars[str[2]].value <= *(int*)vars[str[4]].value) {
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);
							}
						}
						else {

							std::string l;
							while (l != "end") {
								f >> l;

							}
						}
					}
					else if (vars[str[2]].typ==string && vars[str[4]].typ==string) {
						if (*(std::string*)vars[str[2]].value <= *(std::string*)vars[str[4]].value) {
							while (*(std::string*)vars[str[2]].value <= *(std::string*)vars[str[4]].value) {
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);
							}
						}
						else {

							std::string l;
							while (l != "end") {
								f >> l;

							}
						}
					}

				}
			}
			else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
			std::cout << str[9] << " variable is not initialized " << std::endl;;
			exit(EXIT_FAILURE);
			}
		}


		if (str[3] == "==") {
			if (vars.count(str[2]) == 1) {
				if (vars.count(str[4]) == 0) {
					if (vars[str[2]].typ == INT && is_number(str[4])) {
						if (*(int*)vars[str[2]].value == std::stoi(str[4])) {
							while (*(int*)vars[str[2]].value == std::stoi(str[4]))
							{
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);
								
							}
						}
						else {

							std::string l;

							while (l != "end") {
								f >> l;

							}

						}
					}

					else if (vars[str[2]].typ==string && !is_number(str[4])) {
						if (*(std::string*)vars[str[2]].value == str[4]) {
							while (*(std::string*)vars[str[2]].value == str[4])
							{
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);

							}
						}
						else {

							std::string l;

							while (l != "end") {
								f >> l;

							}

						}
					}

				}
				else {
					if (vars[str[2]].typ == INT && vars[str[4]].typ == INT) {
						if (*(int*)vars[str[2]].value == *(int*)vars[str[4]].value) {
							while (*(int*)vars[str[2]].value == *(int*)vars[str[4]].value) {
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);
							}
						}
						else {

							std::string l;
							while (l != "end") {
								f >> l;

							}
						}
					}
					else if (vars[str[2]].typ==string && vars[str[4]].typ==string) {
						if (*(std::string*)vars[str[2]].value == *(std::string*)vars[str[4]].value) {
							while (*(std::string*)vars[str[2]].value == *(std::string*)vars[str[4]].value) {
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);
							}
						}
						else {

							std::string l;
							while (l != "end") {
								f >> l;

							}
						}
					}

				}
			}
			else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
			std::cout << str[9] << " variable is not initialized " << std::endl;;
			exit(EXIT_FAILURE);
			}

		}




		if (str[3] == "!=") {
			if (vars.count(str[2]) == 1) {
				if (vars.count(str[4]) == 0) {
					if (vars[str[2]].typ == INT && is_number(str[4])) {
						if (*(int*)vars[str[2]].value != std::stoi(str[4])) {
							while (*(int*)vars[str[2]].value != std::stoi(str[4]))
							{
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);

							}
						}
						else {

							std::string l;

							while (l != "end") {
								f >> l;

							}

						}
					}

					else if (vars[str[2]].typ==string && !is_number(str[4])) {
						if (*(std::string*)vars[str[2]].value != str[4]) {
							while (*(std::string*)vars[str[2]].value != str[4])
							{
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);

							}
						}
						else {

							std::string l;

							while (l != "end") {
								f >> l;

							}

						}
					}

				}
				else {
					if (vars[str[2]].typ == INT && vars[str[4]].typ == INT) {
						if (*(int*)vars[str[2]].value != *(int*)vars[str[4]].value) {
							while (*(int*)vars[str[2]].value != *(int*)vars[str[4]].value) {
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);
							}
						}
						else {

							std::string l;
							while (l != "end") {
								f >> l;

							}
						}
					}
					else if (vars[str[2]].typ==string && vars[str[4]].typ==string) {
						if (*(std::string*)vars[str[2]].value != *(std::string*)vars[str[4]].value) {
							while (*(std::string*)vars[str[2]].value != *(std::string*)vars[str[4]].value) {
								std::string l1;
								f.seekp(std::ios_base::beg);
								while (l1 != "do") {
									f >> l1;

								}
								Helper2(str, f);
							}
						}
						else {

							std::string l;
							while (l != "end") {
								f >> l;

							}
						}
					}

				}
			}
			else if (decmap.count(str[9]) == 1 && vars.count(str[9]) == 0) {
			std::cout << str[9] << " variable is not initialized " << std::endl;;
			exit(EXIT_FAILURE);
			}

		}
	}

	void Interpreter::Checking(std::string* str, int k, std::fstream& f)
	{
		
		if (str[0] == "sum") {
			Sum(str, k);
		}
		else if (str[0] == "sub") {
			Subtract(str, k);

		}
		else if (str[0] == "mul") {
			Multiplication(str, k);

		}
		else if (str[0] == "quot") {
			QuotientDivision(str, k);

		}
		else if (str[0] == "rem") {
			RemainderDivision(str, k);

		}
		else if (str[0] == "store") {
			
			Assignment(str);

		}
		else if (str[0] == "declare") {
			
			VariableDecl(str);

		}
		else if (str[0] == "stosum") {
		
			Stosum(str);

		}
		else if (str[0] == "stosub") {
			Stosub(str);

		}
		else if (str[0] == "stomul") {
			Stomul(str);

		}
		else if (str[0] == "stoquot") {
			Stoquot(str);

		}
		else if (str[0] == "storem") {
			Storem(str);

		}
		else if (str[0] == "printel") {
		
			Printel(str, k);

		}

		else if (str[0] == "inc") {
			Inc(str);

		}
		else if (str[0] == "dec") {
			Dec(str);

		}
		else if (str[0] == "loop") {
			Loop(str, f);

		}
		else if (str[0] == "check") {

			Ifststemant(str, f);

		}
	}

	void Interpreter::Parser() {
		int k = 0;
		int j = 0;
		std::string str[20];
		std::fstream f("new1.int21");

		while (!f.eof()) {

			std::string line;
			f >> line;
			str[j] = line;
			j++;

			if (f.peek() == '\n') {
				Checking(str, k, f);
				for (int m = 0; m < 11; m++) {
					str[m].clear();
				}
				j = 0;

			}

		}
	}
