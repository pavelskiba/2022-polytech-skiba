## Without `virtual`

```
Person::ctor
Teacher::ctor
Student::ctor
TA::ctor
2
5
Andrey Panchenko  and Sasha Ekordin
TA::dtor
Student::dtor
Teacher::dtor
Person::dtor

```

## With `virtual`

```
Person::ctor
Teacher::ctor
Student::ctor
TA::ctor
2
5
DefaultName 
Andrey Panchenko and Sasha Ekordin
TA::dtor
Student::dtor
Teacher::dtor
Person::dtor
```