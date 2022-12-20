# RpgWorld2

<a name="start"></a>
## Code Styling

<a name="classfunctionsandother"></a>
#### Class functions & other

Используемые стили:
1. **camelCase** - должен начинаться со строчной буквы, а первая буква каждого последующего слова должна 
быть заглавной. Все слова при этом пишутся слитно между собой. ```Пример camelCase для имени переменной camel case var – camelCaseVar.```
2. **snake_case** - чтобы писать в стиле snake_case, нужно просто заменить пробелы знаками подчеркивания. 
Все слова при этом пишутся строчными буквами. Можно использовать snake_case, смешивая его с camelCase 
и PascalCase. ```Пример snake_case для имени переменной snake case var – snake_case_var.```
3. **kebab-case** - похож на snake_case, только в нем пробелы заменяются на дефисы. Слова также пишутся 
строчными буквами. Опять же, его можно смешивать с camelCase и PascalCase, но в этом нет смысла. ```Пример
 kebab-case для переменной kebab case var – kebab-case-var.```
4. **PascalCase** - каждое слово начинается с заглавной буквы (в отличие от camelCase, где первое слово начинается 
со строчной). ```Пример PascalCase для переменной pascal case var – PascalCaseVar.```

<a name="rules"></a>
##### Правила написания

* ```virtual функции``` всегда пишуется **snake_case**
* ```base class функции``` всегда пишутся **camelCase**
* ```static/constexpr``` пишутся **UPPER_CASE**
* ```private class functions``` пишутся **\__camelCase**
* ```protected``` исключён от использования, в проекте применяется либо private либо public
* ```constructor/destructor``` всегда **явно** инициализированы
* ```types``` пишутся с заглавной (в проекте используются свои типы, [см. GameSyste.hpp](#gamesystem))
* ```unclassed functions in GameSystem.hpp``` всегда пишутся **PascalCase**
<a name="gamesystem"></a>
#### "GameSystem.hpp"

* ```GameSystem.hpp``` хранит в себе все системные includes необходимые для запуска программы, 
если мы создаём новый файл, то ```#include "GameSystem.hpp"``` в нём быть обязан.
* ```GameSystem.hpp``` хранит все системные **namespace**

