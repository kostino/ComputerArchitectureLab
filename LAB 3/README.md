# Εργασία Τρίτου Εργαστηρίου Αρχιτεκτονικής Υπολογιστών ΤΗΜΜΥ 2019

**Βλάχος Άγγελος** ΑΕΜ : 9087  
**Τριαρίδης Κωνσταντίνος** ΑΕΜ : 9159

### Περιεχόμενα
1. [Εύρεση στοιχείων για  default υποσύστημα μνήμης από αρχείο config.ini](https://github.com/kostino/ComputerArchitectureLab1/tree/master/LAB%202#εύρεση-στοιχείων-για-default-υποσύστημα-μνήμης-από-αρχείο-configini)
2. [Καταγραφή αποτελεσμάτων benchmarks για default τιμές](https://github.com/kostino/ComputerArchitectureLab1/tree/master/LAB%202#καταγραφή-αποτελεσμάτων-benchmarks-για-default-τιμές)
3. [Αλλαγή ρολογιού στα 1GHz και σύγκριση χρόνου εκτέλεσης](https://github.com/kostino/ComputerArchitectureLab1/tree/master/LAB%202#αλλαγή-ρολογιού-στα-1ghz-και-σύγκριση-χρόνου-εκτέλεσης)  
4. [Αλλαγή παραμέτρων και benchmarks](https://github.com/kostino/ComputerArchitectureLab1/tree/master/LAB%202#αλλαγή-παραμέτρων-και-benchmarks)  
5. [Βελτιστοποίηση κόστους/απόδοσης](https://github.com/kostino/ComputerArchitectureLab1/tree/master/LAB%202#βελτιστοποίηση-κόστουςαπόδοσης)  
6. [Κριτική Εργασίας](https://github.com/kostino/ComputerArchitectureLab1/tree/master/LAB%202#κριτική-εργασίας)

## Βήμα 1

### Πληροφορίες για dynamic power και leakage από McPAT

Ως dynamic power ορίζεται η ισχύς που καταναλώνεται για την φόρτιση και αποφόρτιση των χωρητικών φορτίων στον επεξεργαστή και εξαρτάται από κατασκευαστικούς παράγοντες του επεξεργαστή όπως η συνολική χωρητικότητα, η τάση τροφοδοσίας, η μεταβολή της τάσης κατά την φόρτιση αποφόρτιση των πυκνωτών και η συχνότητα του ρολογιού του επεξεργαστή αλλά και από έναν συντελεστή δραστηριότητας a ο οποίος καταδεικνύει το ποσοστό της χωρητικότητας που φορτίζεται σε έναν κύκλο ρολογιού από κάποιο πρόγραμμα και προφανώς εξαρτάται από το συγκεκριμένο πρόγραμμα που εκτελείται ( όχι από τη διάρκεια εκτέλεσης ).  
Το leakage power οφείλεται στην απώλεια ενέργειας λόγω διάχυσης από τα τρανζιστορ του επεξεργαστή λόγω των φυσικών ατελειών στην κατασκευή τους . Υπάρχουν δύο είδη leakage power : Το subthreshold leakage το οποίο οφείλεται στην πολύ μικρή ποσότητα ρεύματος που διαρρέει από το source στο drain των τρανζίστορ που βρίσκονται σε off-state και το gate leakage που οφείλεται σε μικρή ποσότητα ρεύματος που διαρρέει το gate των τρανζίστορ και αλλάζει ανάλογα με την κατάσταση του τρανζίστορ.  
Τελικά διαφορετικά προγράμματα στον ίδιο επεξεργαστή σίγουρα θα έχουν διαφορετικό dynamic power και ενδεχομένως να έχουν και λίγο διαφορετικό leakage power καθώς η αρχιτεκτονική του ενός μπορεί να έχει περισσότερα τρανζίστορ σε κατάσταση που να διαρρέει περισσότερο ρεύμα. 

### Σύγκριση διάρκειας μπαταρίας γνωρίζοντας μόνο ισχύ

Για να διευκρινίσουμε την διάρκεια μπαταρίας για την εκτέλεση ενός προγράμματος δεν αρκεί να γνωρίζουμε την ισχύ των επεξεργαστών καθώς εάν έχουν διαφορετική απόδοση (χρονική) στην εκτέλεση του προγράμματος θα μπορούσε ο επεξεργαστής που καταναλώνει περισσότερη ισχύ να καταναλώνει συνολικά λιγότερη ενέργεια. Δεν υπάρχει τρόπος να γνωρίζουμε πλήρως μόνο με τα δεδομένα του McPAT. Χρειαζόμαστε τον χρόνο εκτέλεσης του προγράμματος,  δηλαδή δεδομένα από έναν προσομοιωτή όπως ο gem5.

|                       |   bzip  |   mcf  |  hmmer |  sjeng  |   libm  |
|:---------------------:|:-------:|:------:|:------:|:-------:|:-------:|
|   Execution time(ms)  |  83.982 | 64.955 | 59.396 | 513.528 | 174.671 |
|          CPI          |  1.6797 | 1.2991 | 1.1879 | 10.2706 |  3.4934 |
| L1 icache missrate(%) |  0.0077 | 2.3612 | 0.0221 |  0.0020 |  0.0094 |
| L1 dcache missrate(%) |  1.4798 | 0.2108 | 0.1637 | 12.1831 |  6.0972 |
|  L2 cache missrate(%) | 28.2163 | 5.5046 | 7.7760 | 99.9972 | 99.9944 |

![Time](https://github.com/kostino/ComputerArchitectureLab2/blob/master/step%201/Default%202GHz/images/time.png?raw=true)
![CPI](https://github.com/kostino/ComputerArchitectureLab2/blob/master/step%201/Default%202GHz/images/cpi.png?raw=true)
![Icache](https://github.com/kostino/ComputerArchitectureLab2/blob/master/step%201/Default%202GHz/images/icache.png?raw=true)
![Dcache](https://github.com/kostino/ComputerArchitectureLab2/blob/master/step%201/Default%202GHz/images/dcache.png?raw=true)
![L2](https://github.com/kostino/ComputerArchitectureLab2/blob/master/step%201/Default%202GHz/images/l2.png?raw=true)

### Xeon vs ARM A9 με McPAT

Η συνολική ενέργεια που καταναλώνει ένας επεξεργαστής για την εκτέλεση ενός προγράμματος υπολογίζεται ως εξής :  
_Energy = (Runtime dynamic power + total leakage power) * Time_
Στοιχεία McPAT:
* Xeon : Runtime Dynamic = 72.9 W , Total Leakage = 36.8 W , Total power= 109.7 W
* ARM A9 : Runtime Dynamic = 2.96 W , Total Leakage = 0.10 W , Total power= 4.06 W

Από τα στοιχεία φαίνεται ότι αν ο Xeon είναι 40 φορές πιο γρήγορος τότε θα καταναλώνει λιγότερη ενέργεια για την εκτέλεση του προγράμματος. Αν βέβαια δεν απενεργοποιηθεί μετά το σύστημα ο Xeon θα συνεχίσει να καταναλώνει το leakage power ενώ ο ARM τρέχει το πρόγραμμα συνεπώς συνολικά ο Xeon θα καταναλώσει πολύ περισσότερη ενέργεια( κυρίως λόγω του τεράστιου leakage power που καταναλώνει) άρα ο ARM είναι σίγουρα πιο energy-efficient.

## Βήμα 2

### Πληροφορίες για το delay - energy
Το delay είναι ο χρόνος εκτέλεσης του προγράμματος και θα το βρούμε από τα στατιστικά του gem5: στο αρχείο stats.txt το sim_seconds.  
Το energy υπολογίζεται ως εξής : energy = (leakage + Runtime dynamic) * time   
Χρησιμοποιούμε το script print_energy που δόθηκε τροποποιημένο για να αυτοματοποιήσουμε τη διαδικασία. 

#### Μέτρηση EDAP στα προηγούμενα benchmarks

![1G](https://github.com/kostino/ComputerArchitectureLab2/blob/master/bench%20images/ls.png?raw=true)
![1G](https://github.com/kostino/ComputerArchitectureLab2/blob/master/bench%20images/ls.png?raw=true)
![1G](https://github.com/kostino/ComputerArchitectureLab2/blob/master/bench%20images/ls.png?raw=true)
![1G](https://github.com/kostino/ComputerArchitectureLab2/blob/master/bench%20images/ls.png?raw=true)
![1G](https://github.com/kostino/ComputerArchitectureLab2/blob/master/bench%20images/ls.png?raw=true)
 L1 cache κοστίζουν 1 μονάδα κόστους ενώ 2MB L2 cache κοστίζουν επίσης 1 μονάδα κόστους.  
Όσον αφορά την αλλαγή του μεγέθους , είτε στην L1 είτε στην L2 ,διπλασιασμός του μεγέθους σημαίνει διπλασιασμό του hardware που χρησιμοποιείται άρα και περίπου διπλασιασμό του κόστους, δηλαδή έχω μία σχεδόν γραμμική σχέση μεγέθους-κόστους.
Έχουμε δηλαδή :  


Βέλτιστες προδιαγραφές EDAP για κάθε benchmark:  
**Για το bzip:**
* L1 icache size :32 kB
* L1 icache associativity : 2-way
* L1 dcache size :32 kB
* L1 dcache associativity :2-way
* L2 cache size :1 MB
* L2 cache associativity :8-way
* Cache line size :128 B

**Για το mcf:**
* L1 icache size :32 kB
* L1 icache associativity : 4-way
* L1 dcache size :32 kB
* L1 dcache associativity :2-way
* L2 cache size :1 MB
* L2 cache associativity :8-way
* Cache line size :64 B

**Για το hmmer:**
* L1 icache size :32 kB
* L1 icache associativity : 2-way
* L1 dcache size :32 kB
* L1 dcache associativity :2-way
* L2 cache size :1 MB
* L2 cache associativity :8-way
* Cache line size :128 B

**Για το sjeng:**
* L1 icache size :32 kB
* L1 icache associativity : 2-way
* L1 dcache size :32 kB
* L1 dcache associativity :2-way
* L2 cache size :1 MB
* L2 cache associativity :8-way
* Cache line size :128 B

**Για το libm:**
* L1 icache size :32 kB
* L1 icache associativity : 2-way
* L1 dcache size :32 kB
* L1 dcache associativity :2-way
* L2 cache size :1 MB
* L2 cache associativity :8-way
* Cache line size :128 B

### Κριτική εργασίας
Σε αυτή την εργασία ξοδέψαμε πολύ χρόνο στην αναζήτηση πληροφοριών για τον τρόπο μοντελοποίησης της ισχύος από τον McPAT και αποκτήσαμε μια διαφορετική νοοτροπία σχετικά με την κατασκευή επεξεργαστών, σκεπτόμενοι περισσότερο την κατανάλωση ενέργειας και τη σχέση ενέργειας απόδοσης παρά τη στείρα βελτιστοποίηση της απόδοσης. Η διαδικασία της αυτοματοποίησης των benchmark μας προέτρεψε να μάθουμε να γράφουμε και να τροποποιούμε python scripts για να μαζέψουμε δεδομένα από αρχεία, γνώση που θα μας φανεί ιδιαίτερα χρήσιμη και επαγγελματικά. Συνολικά το εργαστήριο αν και εξαιρετικά ενδιαφέρον ήταν δύσκολο στην εκπόνηση και "μπέρδευε" τον φοιτητή καθώς παρά την κατηγοριοποίηση του ως εργαστήριο ήταν περισσότερο μια μεγάλη εργασία εξαμήνου καθώς όλη η δουλειά γινόταν από πρίν στο σπίτι καθώς το περίπλοκο και χρονοβόρο περιεχόμενο του εργαστηρίου δεν επέτρεπε την εκπόνηση στον περιορισμένο χρόνο εκεί.Αυτό βέβαια σήμαινε ότι κατά τη διάρκεια του εργαστηρίου η ουσιαστική αλληλεπίδραση με τον διδάσκοντα για απορίες, διευκρινίσεις, βοήθεια ήταν περιορισμένη και η ώρα του εργαστηρίου ήταν περισσότερο απλώς ώρα εξέτασης και όχι δουλειάς.Βέβαια στο πλαίσιο του εργαστήριου μάθαμε πάρα πολλά πράγματα που μας έφεραν σε επαφή με την πραγματική δουλειά ενός αρχιτέκτονα υπολογιστών και προσωπικά μας κίνησε το ενδιαφέρον να ασχοληθούμε περαιτέρω με την αρχιτεκτονική σαν αντικείμενο.

### Πηγές
* [Computer Architecture, a quantitative approach](http://uni-site.ir/khuelec/wp-content/uploads/Computer-Architecture-A-Quantitative-Approach.pdf)
* [ARS Technica : Understanding CPU caching and performance](https://arstechnica.com/gadgets/2002/07/caching/)
* [James R. Goodman, "Using Cache Memory to Reduce Processor-Memory Traffic." 25 Years ISCA: Retrospectives and Reprints 1998: 255-262](https://dblp.uni-trier.de/db/conf/isca/reprints98.html)
* [High Performance Embedded Architectures and Compilers : Example Design p. 342-350](https://books.google.gr/books?id=9j5A9KKHF4wC&pg=PA343&lpg=PA343&dq=cache%20block%20size%20cost&source=bl&ots=RA1iwckJ63&sig=ACfU3U1s4_s_scSBng2YiF-NcubSGQ4WJQ&hl=el&sa=X&ved=2ahUKEwiZ-7r-_bfmAhV_UhUIHdy9DsoQ6AEwE3oECAoQAQ&fbclid=IwAR3VXGyE6DQK-CeaKwNvmaABf8zHao25E8jM3IVQKZEWqoMMvlFKfygSiVg#v=onepage&q=cache%20block%20size%20cost&f=false)
