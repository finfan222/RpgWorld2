# RpgWorld2

<a name="start"></a>
## Code Styling

<a name="classfunctionsandother"></a>
#### Class functions & other
* ```virtual функции``` всегда пишуется **snake_case**
* ```base class функции``` всегда пишутся **camelCase**
* ```static/constexpr``` пишутся **UPPER_CASE**
* ```private class functions``` пишутся **\__camelCase**
* ```protected``` исключён от использования, в проекте применяется либо private либо public
* ```constructor/destructor``` всегда **явно** инициализированы
* ```types``` пишутся с заглавной (в проекте используются свои типы, [см. GameSyste.hpp](#gamesystem))

<a name="gamesystem"></a>
#### "GameSystem.hpp"

* ```GameSystem.hpp``` хранит в себе все системные includes необходимые для запуска программы, 
если мы создаём новый файл, то ```#include "GameSystem.hpp"``` в нём быть обязан.
* ```GameSystem.hpp``` хранит все системные **namespace**

