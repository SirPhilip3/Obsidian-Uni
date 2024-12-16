---
publish: true
creation: 2024-12-16T15:37:00
aliases:
  - CSR
---
Un **CSR** è un file scritto in uno specifico formato che contiene le informazioni di colui che vuole un [[Certificate]] per una chiave `Pub_A`

Una **CSR** viene firmata con la `Priv_A`

$$CSR = \{ Pub\_A, \text{"Alice"} , E(Priv\_A,(Pub\_A, \text{"Alice"})) \}$$