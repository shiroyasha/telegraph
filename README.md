# Telegraph - The service definition protocol

Telegraph is a tool for defining public APIs for your services.

Based on the public API, telegraph can generate clients and servers for your
favorite programming language.

Here is a very simple example for a Message Board service.

```
struct User {
  Integer id;
  String username;
}

event user_created publishes User;

event message_published publishes {
  User publisher;
  String message;
}

error UsenameAlreadyTaken {
  String error_description;
}

User create_user(String username) throws UsernameAlreadyTaken;
void publish_message(Integer user_id, String message);
```


## Types

| Type       | Description                                            |
| -----------|--------------------------------------------------------|
| SmallInt   | 4 bytes integer                                        |
| Integer    | 4 bytes integer                                        |
| BigInt     | 8 bytes integer                                        |
| Float      | 4 bytes floating point number                          |
| Double     | 8 bytes floating point number                          |
| Boolean    | True of False valued type                              |
| String     | Variable sized character array                         |
| UUID       | UUID as defined by RFC 4122, ISO/IEC 9834-8:2005       |
| JSON       | Javascript object notation type                        |
| XML        | XML type                                               |
| Date       | Date value                                             |
| Time       | Time value                                             |
| DateTime   | Date and Time value                                    |

Arrays are represented with angle brackets. For example, an array of integers:

```
[Integer]
```

## Data Structures

You should define all the data structures your services handles. For example, if
your service handles users, you should define a `User` data structure:

```
struct User {
  String name;
  Integer age;
}
```

## Events

A telegraph service is able to define events, and other services can subscribe
to those events. For example, if you have a service that handles users, you can
define and trigger a `user_created` event every time a user is created:

```
event user_created publishes User;
```

## Functions

A telegraph service can define multiple functions that the consumers can call.

Every function should define the following:

- parameters
- errors
- return value

For example, if you want to divide two numbers:

```
Float divide(Float a, Float b) throws DivisionbyZero;
```

If the function doesn't return anything, use `void` to represent the absence of
the return type. For example, if you have a service that manages users, and you
want to define a function that deletes a user:

```
void remove_user(Integer user_id) throws UserNotFound;
```

## Errors

When something goes wrong in your service you should use an Error to notify the
caller about the issue. For example:

```
error DivisionByZero {
  String message;
}

function divive(Integer a, Integer b) returns Float throws DivisionByZero;
```

## Examples

- [Address Book](docs/examples/addressbook.tg)

## LICENSE

The MIT License (MIT)
Copyright (c) 2016 Igor Sarcevic

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
