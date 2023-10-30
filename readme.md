# cp_console_chat
Консольный чат для приватного и группового обмена с
ообщениями между пользователями посредством консоли.

## Команда разработчиков:
- Цветков Федор Викторович

### Тимлид:
- Цветков Федор Викторович

## Описание идеи:
Проект реализован на языке C++.
За основу созданы три класса Chat, User и Message. При входе в чат пользователь попадает в меню аутентификацииб где он может зарегистрироваться, либо войти в свой профиль, если он был созда ранее.
После аутентификации пользователь попадает в личное меню, где он может посмотреть всех участников чата, посмотреть сообщения и отправить сообщение приватно, либо всем участникам чата. 
Для хранения данных используется контейнер типа vector.

# Описание типов и функций:
class User - описание объектов типа пользователь.
class Message - описание объектов типа сообщение.
class Chat - Главный класс, где описаны вся логика работы.

- **start()** - запускает работу чата.
- **authorizationMenu()** - Меню авторизации.
- **customMenu()** - Меню пользователя.
- **signUp()** - Регистрация нового пользователя.
- **authorzation()** - Вход для зарегистрированного пользователя.
- **showChat()** - Просмотр сообщений.
- **showAllUserName()** - Просмотр всех пользователей чата
- **addMessage()** - Добавление сообщения.

###### Весь проект реализовал:
- Цветков Федор Викторович