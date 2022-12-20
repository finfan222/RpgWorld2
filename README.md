# RpgWorld2

<a name="start"></a>
## Code Styling

<a name="classfunctionsandother"></a>
#### Class functions & other

������������ �����:
1. **camelCase** - ������ ���������� �� �������� �����, � ������ ����� ������� ������������ ����� ������ 
���� ���������. ��� ����� ��� ���� ������� ������ ����� �����. ```������ camelCase ��� ����� ���������� camel case var � camelCaseVar.```
2. **snake_case** - ����� ������ � ����� snake_case, ����� ������ �������� ������� ������� �������������. 
��� ����� ��� ���� ������� ��������� �������. ����� ������������ snake_case, �������� ��� � camelCase 
� PascalCase. ```������ snake_case ��� ����� ���������� snake case var � snake_case_var.```
3. **kebab-case** - ����� �� snake_case, ������ � ��� ������� ���������� �� ������. ����� ����� ������� 
��������� �������. ����� ��, ��� ����� ��������� � camelCase � PascalCase, �� � ���� ��� ������. ```������
 kebab-case ��� ���������� kebab case var � kebab-case-var.```
4. **PascalCase** - ������ ����� ���������� � ��������� ����� (� ������� �� camelCase, ��� ������ ����� ���������� 
�� ��������). ```������ PascalCase ��� ���������� pascal case var � PascalCaseVar.```

<a name="rules"></a>
##### ������� ���������

* ```virtual �������``` ������ �������� **snake_case**
* ```base class �������``` ������ ������� **camelCase**
* ```static/constexpr``` ������� **UPPER_CASE**
* ```private class functions``` ������� **\__camelCase**
* ```protected``` �������� �� �������������, � ������� ����������� ���� private ���� public
* ```constructor/destructor``` ������ **����** ����������������
* ```types``` ������� � ��������� (� ������� ������������ ���� ����, [��. GameSyste.hpp](#gamesystem))
* ```unclassed functions in GameSystem.hpp``` ������ ������� **PascalCase**
<a name="gamesystem"></a>
#### "GameSystem.hpp"

* ```GameSystem.hpp``` ������ � ���� ��� ��������� includes ����������� ��� ������� ���������, 
���� �� ������ ����� ����, �� ```#include "GameSystem.hpp"``` � �� ���� ������.
* ```GameSystem.hpp``` ������ ��� ��������� **namespace**

