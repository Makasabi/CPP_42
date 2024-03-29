#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "colors.hpp"
#include "MateriaSource.hpp"

int main() {
{
	std::cout << _BOLD << "-----------TEST POOL 1-----------" << _END << std::endl;

	std::cout << "\nCreating a MateriaSource src and learning Materia Ice and Materia Cure" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\nCreating 2 Characters : Bill and Boule" << std::endl;
	Character* bill = new Character("Bill");
	Character* boule = new Character("Boule");

	std::cout << "\nTrying to create Materia 'lava' and to add it to Bill materias." << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("lava");
	bill->equip(tmp);
	std::cout << "\nTrying to create Materia 'ice' and to add it to Bill materias." << std::endl;
	tmp = src->createMateria("ice");
	bill->equip(tmp);
	std::cout << "\nTrying to create Materia 'cure' and to add it to Bill materias." << std::endl;
	tmp = src->createMateria("cure");
	bill->equip(tmp);

	std::cout << "\nBill using his 2 Materias from his materias array [0], then [1], then [8]" << std::endl;
	bill->use(0, *boule);
	bill->use(1, *boule);
	bill->use(8, *boule);

	std::cout << "\nCreating new Character Bill2" << std::endl;
	Character* bill2 = new Character();
	std::cout << "\nTrying to create Materia 'cure' and to add it to Bill2 materias." << std::endl;
	tmp = src->createMateria("cure");
	bill2->equip(tmp);
	std::cout << "\nTrying to create Materia 'ice' and to add it to Bill2 materias." << std::endl;
	tmp = src->createMateria("ice");
	bill2->equip(tmp);


	std::cout << "\nBill2 using his 2 Materias from his materias array [0], then [1]" << std::endl;
	bill2->use(0, *boule);
	bill2->use(1, *boule);

	std::cout << "\nCopying Bill2 from Bill" << std::endl;
	*bill2 = *bill;

	std::cout << "\nDeleting Bill" << std::endl;
	delete bill;

	std::cout << "\nBill2 using his 2 Materias from his materias array [0], then [1]" << std::endl;
	bill2->use(0, *boule);
	bill2->use(1, *boule);

	std::cout << "\nDeleting Bill2 & Boule\n" << std::endl;
	delete src;
	delete bill2;
	delete boule;
}
{
	std::cout << _BOLD << "\n-----------TEST POOL 2-----------" << _END << std::endl;

	std::cout << "\nCreating a MateriaSource src and learning Materia Ice and Materia Cure" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\nCreating Characters : 'me'" << std::endl;
	ICharacter* me = new Character("me");

	std::cout << "\nTrying to create Materia 'lava' and to add it to me materias." << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("lava");
	me->equip(tmp);
	std::cout << "\nTrying to create Materia 'ice' and to add it to me materias." << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << "\nTrying to create Materia 'cure' and to add it to me materias." << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "\nCreating Characters : 'bob'" << std::endl;
	ICharacter* bob = new Character("bob");

	std::cout << "\nMe using materias[0] and [1] on bob" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\nDeleting bob, me and src" << std::endl;
	delete bob;
	delete me;
	delete src;

	return 0;
}
}