Sokoban
=======

![Sokoban Game](https://i.imgur.com/9HtXYzH.png)

This project is a refactored and enhanced version of a simple Sokoban clone. The original implementation was procedural in nature and written in C++. I transformed it into a more structured and maintainable object-oriented design, focusing on encapsulation, modularity, and clean architecture.
My goal was not only to improve the codebase but also to gain hands-on experience applying object-oriented programming (OOP) principles and advanced C++ features. I also replaced the static level representation with a dynamic level loading system based on .sl files using a run-length encoding format.
[here](http://www.sokobano.de/wiki/index.php?title=Level_format).

![telegram-cloud-photo-size-2-5357335651919459785-y](https://github.com/user-attachments/assets/3c2b817c-dd6d-400e-bd28-2a759331ee2a)

![telegram-cloud-photo-size-2-5357335651919459786-y](https://github.com/user-attachments/assets/9917aaf7-1e87-4249-907a-bc9a271cf67c)

This project aims to strengthen understanding of object-oriented programming (OOP) concepts such as encapsulation and data abstraction. It also introduces practical applications of exception handling for robust error management dealing with file input and output.


![telegram-cloud-photo-size-2-5357335651919459783-y](https://github.com/user-attachments/assets/bf7a45a6-ba3d-43f1-9d02-0d63f782d5df)


![telegram-cloud-photo-size-2-5357335651919459784-y](https://github.com/user-attachments/assets/1352d0d4-5c15-49b9-baaa-e9d6849265c1)

Key Features

 Object-Oriented Redesign        
Level Class        
All level-related logic and state (layout, objects, goals) have been encapsulated in a Level class. This class is responsible for storing the map, rendering it, checking win conditions, and handling interactions between the player and boxes.        
Player Class        
The player logic (movement, collision checks, game controls) is now handled by a Player class. The player interacts directly with the level state and is responsible for handling user inputs.        

 Dynamic Level Loading        
The game now reads level data from .sl files located in the /data directory. These files use a simple run-length encoding scheme to represent tile layouts. I implemented a parser that reads and decodes this format, dynamically generating level maps at runtime.      

Robust Error Handling        
To ensure stability and better user feedback, I introduced exception handling for the level loader. Errors such as missing files, malformed encodings, or unexpected symbols are caught and reported gracefully, preventing game crashes.

![telegram-cloud-photo-size-2-5357335651919459787-y](https://github.com/user-attachments/assets/4a536a61-34b4-49ee-963c-d2d7bae89b40)



Building and Running the Game        
 Requirements        
C++11 or later        
Make (or another build system)        
 Compilation        
make        
./sokoban        
You can also compile manually:        
g++ -std=c++11 -o sokoban src/*.cpp        

![Sokoban Game](https://i.imgur.com/9HtXYzH.png)

Этот проект представляет собой переработанную и улучшенную версию простого клона Sokoban. Первоначальная реализация была процедурной по своей природе и написана на C++. Я преобразовал ее в более структурированную и поддерживаемую объектно-ориентированную конструкцию, сосредоточившись на инкапсуляции, модульности и чистой архитектуре.    
Моей целью было не только улучшить кодовую базу, но и получить практический опыт применения принципов объектно-ориентированного программирования (ООП) и расширенных функций C++. Я также заменил статическое представление уровня на динамическую систему загрузки уровней на основе файлов .sl с использованием формата кодирования длины серии.    
[здесь](http://www.sokobano.de/wiki/index.php?title=Level_format).

![telegram-cloud-photo-size-2-5357335651919459785-y](https://github.com/user-attachments/assets/3c2b817c-dd6d-400e-bd28-2a759331ee2a)

![telegram-cloud-photo-size-2-5357335651919459786-y](https://github.com/user-attachments/assets/9917aaf7-1e87-4249-907a-bc9a271cf67c)

Этот проект направлен на укрепление понимания концепций объектно-ориентированного программирования (ООП), таких как инкапсуляция и абстракция данных. Он также знакомит с практическими приложениями обработки исключений для надежного управления ошибками при вводе и выводе файлов.

![telegram-cloud-photo-size-2-5357335651919459783-y](https://github.com/user-attachments/assets/bf7a45a6-ba3d-43f1-9d02-0d63f782d5df)

![telegram-cloud-photo-size-2-5357335651919459784-y](https://github.com/user-attachments/assets/1352d0d4-5c15-49b9-baaa-e9d6849265c1)

Основные особенности

Объектно-ориентированный редизайн

Класс уровня

Вся логика и состояние, связанные с уровнем (макет, объекты, цели), были инкапсулированы в классе уровня. Этот класс отвечает за хранение карты, ее рендеринг, проверку условий победы и обработку взаимодействий между игроком и ящиками.

Класс Player

Логика игрока (движение, проверка столкновений, управление игрой) теперь обрабатывается классом Player. Игрок напрямую взаимодействует с состоянием уровня и отвечает за обработку ввода пользователя.

Динамическая загрузка уровня        
Теперь игра считывает данные уровня из файлов .sl, расположенных в каталоге /data. Эти файлы используют простую схему кодирования длины серии для представления макетов плиток. Я реализовал парсер, который считывает и декодирует этот формат, динамически генерируя карты уровней во время выполнения.        

Надежная обработка ошибок        
Чтобы обеспечить стабильность и лучшую обратную связь с пользователем, я ввел обработку исключений для загрузчика уровней. Такие ошибки, как отсутствующие файлы, неправильно сформированные кодировки или неожиданные символы, отлавливаются и сообщаются корректно, предотвращая сбои игры.        

![telegram-cloud-photo-size-2-5357335651919459787-y](https://github.com/user-attachments/assets/4a536a61-34b4-49ee-963c-d2d7bae89b40)

Сборка и запуск игры        
Требования        
C++11 или более поздняя версия        
Make (или другая система сборки)        
Компиляция        
make        
./sokoban        
Вы также можете скомпилировать вручную:        

g++ -std=c++11 -o sokoban src/*.cpp
