>[!todo]
>riscrivi es
>#todo

#### 1/12/2023

##### 1 

nome delle pizze per cui almeno 1 ingrediente ha quantità magazzino = 0

```sql
SELECT DISTINCT pi.codpizza, pi.nome -- omonimia
-- joins 
-- 1 natural su codpizza
-- 2 using ( c'è nome sia in pizza che ingrediente )
FROM pizze pi NATURAL JOIN ricette r JOIN ingredienti i USING(codingrediente)
WHERE i.quantitamagazzino = 0
```

algebra relazionale : 

##### 2
```sql
-- nome , prezzo pizze sia mozzarella che prosciutto
SELECT pi.nome , pi.prezzo -- ogni ingrediente nella pizza 1 sola volta non serve il distinct
FROM pizze pi NATURAL JOIN ricette r1 JOIN ingredienti i1 USING(codingrediente)
	-- devo rifare join con le ricette 
	-- devo avere 2 ricette
	JOIN ricette r2 USING(codpizza) -- devono essere della stessa pizza iniziale
	JOIN ingredienti i2 ON i2.codingrediente = r2.codingrediente
WHERE i1.nome='Mozzarella' AND i2.nome='Prosciutto'
```

##### 3
```sql
-- trovare n pizze in cui non c'è il pomodoro
SELECT COUNT(*)
-- nessun ingrediente deve essere pomodoro
FROM pizze pi NATURAL JOIN ricette r JOIN ingredienti i USING(codingrediente)
WHERE i.nome<>'Pomodoro'
-- così controlla solo ogni singolo ingrediente -> non universale 
```

con not existis 

```sql
-- trovare n pizze in cui non c'è il pomodoro
SELECT COUNT(*)
-- nessun ingrediente deve essere pomodoro
FROM pizze pi
-- non esiste un elemento che sia pomodoro 
WHERE NOT EXISTS (SELECT *
				  -- mi interessa ingrediente 
				 FROM ricette r NATURAL JOIN ingredienti i
				  -- non deve esistere in questa pizza un ing pomodoro
				 WHERE i.nome='Pomodoro' AND pi.codpizza = r.codpizza)
```

not in

-----

##### 4

```sql
-- per ogni pizza nome pizze e quante volte ordinata da mario rossi 
-- mai stata ordinata count = 0
-- ordine decrescente m°pizze ordinata
-- per restituire 0 codpizze dalla tabella ordini
SELECT pi.nome , COUNT(o.codpizza) AS numOrdini
-- left per restituire gli 0
-- se pizza mai ordianta da mario rossi aggiunti come null
FROM pizze pi LEFT JOIN ordini o ON pi.codpizza = o.codpizza AND o.nomecliente='Mario Rossi' 
-- WHERE o.nomecliente = 'Mario Rossi' -- solo ordini di mario rossi , non compaiono le pizze non ordinate da mario xxx 
GROUP BY pi.codpizza, pi.nome
ORDER BY numOrdini DESC
```

se condizine nella tebella di dx devo mettere condizione nel join 
count dove ci sono dei null se vogliamo ritornare i null 

##### 5

```sql
-- clienti che hanno ordinato almeno 3 pizze di tipo diverso
SELECT o.nomecliente --distinct prb
FROM ordini o 
ORDER BY o.nomecliente 
-- condizione sul gruppo
HAVING 
```

##### 6

per ogni cliente, trovare il numero dei suoi ordini e il numero di pizze di tipo diverso che ha ordinato. Il risultato deve essere ordinato per il numero degli ordini in senso decrescente;

```sql
SELECT o.nomecliente, COUNT(*) AS numeroOrdini , COUNT(DISTINCT o.codpizza) AS numeroPizze 
FROM ordini o  -- mi basata ordini a meno che non volevo info relative al cliente
GROUP BY o.nomecliente
ORDER BY numeroOrdini DESC
```

##### 8

rovare il nome e il tempo di preparazione delle pizze che contengono almeno quattro ingredienti e non hanno alcun tipo di Funghi;

```sql
SELECT pi.nome , pi.tempoprep
FROM pizze pi NATURAL JOIN ricette r  
-- conto quanti sono gli ingredienti
WHERE NOT EXISTS (SELECT * 
				  FROM ricette r1 NATURAL JOIN ingredienti i  
				  WHERE i.nome LIKE 'Funghi%' AND pi.codpizza = r1.codpizza ) -- deve essitere nella pizza che sto selezionando abbiano funghi
GROUP BY pi.codpizza, pi.nome, pi.tempoprep -- nome prep devono essere presenti poichè devono essere restituiti
HAVING COUNT(*) >= 4
```

sull'having meglio vincoli sul gruppo 

##### 9

restituire nome delle pizze più costose 

```sql
SELECT nome
FROM pizze
WHERE prezzo = (SELECT MAX(prezzo)
				FROM pizze)
```

##### 10

sulle risposte aperte mettere query


## Triggers 


```sql
CREATE FUNCTION no_pc_laptop_fn() RETURNS trigger AS $$
BEGIN 
	IF(NEW.type = 'pc' AND EXISTS(SELECT FROM lab.product WHERE maker = NEW .maker NAD type='laptop') )
	THEN RETURN NULL
	END IF
	RETURN NEW
END
$$ LANGUAGE plpsql

CREATE TRIGGER no_pc_laptop
BEFORE INSERT ON UPDATE
ON product
FOR EACH ROW
EXECUTE FUNCTION no_pc_laptop_fn()
```