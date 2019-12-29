# Εργασία Τρίτου Εργαστηρίου Αρχιτεκτονικής Υπολογιστών ΤΗΜΜΥ 2019

**Βλάχος Άγγελος** ΑΕΜ : 9087  
**Τριαρίδης Κωνσταντίνος** ΑΕΜ : 9159

### Περιεχόμενα
### Βήμα 1
1. [Πληροφορίες για dynamic power και leakage από McPAT](https://github.com/kostino/ComputerArchitectureLab1/tree/master/LAB%203#πληροφορίες-για-dynamic-power-και-leakage-από-mcpat)
2. [Σύγκριση διάρκειας μπαταρίας γνωρίζοντας μόνο ισχύ](https://github.com/kostino/ComputerArchitectureLab1/tree/master/LAB%203#σύγκριση-διάρκειας-μπαταρίας-γνωρίζοντας-μόνο-ισχύ)
3. [Xeon vs ARM A9 με McPAT](https://github.com/kostino/ComputerArchitectureLab1/tree/master/LAB%203#xeon-vs-arm-a9-με-mcpat)  
### Βήμα 2
1. [Πληροφορίες για το delay - energy](https://github.com/kostino/ComputerArchitectureLab1/tree/master/LAB%203#πληροφορίες-για-το-delay---energy)  
2. [Μέτρηση EDAP στα προηγούμενα benchmarks - επιλογή βέλτιστων προδιαγραφών
](https://github.com/kostino/ComputerArchitectureLab1/tree/master/LAB%203#μέτρηση-edap-στα-προηγούμενα-benchmarks---επιλογή-βέλτιστων-προδιαγραφών)  
*  [Κριτική Εργασίας](https://github.com/kostino/ComputerArchitectureLab1/tree/master/LAB%203#κριτική-εργασίας)

## Βήμα 1

### Πληροφορίες για dynamic power και leakage από McPAT

Ως dynamic power ορίζεται η ισχύς που καταναλώνεται για την φόρτιση και αποφόρτιση των χωρητικών φορτίων στον επεξεργαστή και εξαρτάται από κατασκευαστικούς παράγοντες του επεξεργαστή όπως η συνολική χωρητικότητα, η τάση τροφοδοσίας, η μεταβολή της τάσης κατά την φόρτιση αποφόρτιση των πυκνωτών και η συχνότητα του ρολογιού του επεξεργαστή αλλά και από έναν συντελεστή δραστηριότητας a ο οποίος καταδεικνύει το ποσοστό της χωρητικότητας που φορτίζεται σε έναν κύκλο ρολογιού από κάποιο πρόγραμμα και προφανώς εξαρτάται από το συγκεκριμένο πρόγραμμα που εκτελείται ( όχι από τη διάρκεια εκτέλεσης ).  
Το leakage power οφείλεται στην απώλεια ενέργειας λόγω διάχυσης από τα τρανζιστορ του επεξεργαστή λόγω των φυσικών ατελειών στην κατασκευή τους . Υπάρχουν δύο είδη leakage power : Το subthreshold leakage το οποίο οφείλεται στην πολύ μικρή ποσότητα ρεύματος που διαρρέει από το source στο drain των τρανζίστορ που βρίσκονται σε off-state και το gate leakage που οφείλεται σε μικρή ποσότητα ρεύματος που διαρρέει το gate των τρανζίστορ και αλλάζει ανάλογα με την κατάσταση του τρανζίστορ.  
Τελικά διαφορετικά προγράμματα στον ίδιο επεξεργαστή σίγουρα θα έχουν διαφορετικό dynamic power και ενδεχομένως να έχουν και λίγο διαφορετικό leakage power καθώς η αρχιτεκτονική του ενός μπορεί να έχει περισσότερα τρανζίστορ σε κατάσταση που να διαρρέει περισσότερο ρεύμα. 

### Σύγκριση διάρκειας μπαταρίας γνωρίζοντας μόνο ισχύ

Για να διευκρινίσουμε την διάρκεια μπαταρίας για την εκτέλεση ενός προγράμματος δεν αρκεί να γνωρίζουμε την ισχύ των επεξεργαστών καθώς εάν έχουν διαφορετική απόδοση (χρονική) στην εκτέλεση του προγράμματος θα μπορούσε ο επεξεργαστής που καταναλώνει περισσότερη ισχύ να καταναλώνει συνολικά λιγότερη ενέργεια. Δεν υπάρχει τρόπος να γνωρίζουμε πλήρως μόνο με τα δεδομένα του McPAT. Χρειαζόμαστε τον χρόνο εκτέλεσης του προγράμματος,  δηλαδή δεδομένα από έναν προσομοιωτή όπως ο gem5.

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
Χρησιμοποιούμε το script print_energy.py που δόθηκε, τροποποιημένο ,για να αυτοματοποιήσουμε τη διαδικασία. 

### Μέτρηση EDAP στα προηγούμενα benchmarks - επιλογή βέλτιστων προδιαγραφών

Επειδή το EDAP είναι πολυ διαφορετικό για τα benchmarks βοηθάει οπτικά αυτή τη φορά να παρουσιαστεί κάθε benchmark σε δικό του γράφημα.  
Με μωβ είναι η default τιμή και με κίτρινο η τιμή με την εκάστοτε παράμετρο αλλαγμένη για εύκολη σύγκριση.  Όλες οι μετρήσεις στο αρχείο _**data.csv**_


![1G](https://github.com/kostino/ComputerArchitectureLab1/blob/master/LAB%203/images/specbzip.png?raw=true)
![1G](https://github.com/kostino/ComputerArchitectureLab1/blob/master/LAB%203/images/specmcf.png?raw=true)
![1G](https://github.com/kostino/ComputerArchitectureLab1/blob/master/LAB%203/images/spechmmer.png?raw=true)
![1G](https://github.com/kostino/ComputerArchitectureLab1/blob/master/LAB%203/images/speclibm.png?raw=true)
![1G](https://github.com/kostino/ComputerArchitectureLab1/blob/master/LAB%203/images/specsjeng.png?raw=true)
 
 
 Παρατηρούμε ότι για όλα τα benchmarks η αύξηση του dcache associativity μειώνει το EDAP αφού μειώνει το Energy και το Area(Δεν μπορούσαμε να καταλάβουμε γιατί...) ,ενώ γενικά μικρότερες μνήμες (και L1 και L2) έχουν μικρότερο Area με ίδιο περίπου delay και energy άρα μικρότερο EDAP. Επίσης μεγαλύτερο cache line size αυξάνει τρομερά το Area άρα και το EDAP παρόλο που μειώνει το delay. Επίσης στο mcf το icache associativity μας δίνει καλύτερο EDAP αφού βελτιώνει πάρα πολύ την απόδοση όπως είδαμε στην προηγούμενη εργασία. Συνεπώς καταλήγουμε στις βέλτιστες παραμέτρους για κάθε bench:

##### Βέλτιστες προδιαγραφές όσον αφορά τοEDAP για κάθε benchmark:  
**Για το bzip:**
* L1 icache size :32 kB
* L1 icache associativity : 2-way
* L1 dcache size :32 kB
* L1 dcache associativity :4-way
* L2 cache size :1 MB
* L2 cache associativity :8-way
* Cache line size :64 B

**Για το mcf:**
* L1 icache size :32 kB
* L1 icache associativity : 4-way
* L1 dcache size :32 kB
* L1 dcache associativity :4-way
* L2 cache size :1 MB
* L2 cache associativity :8-way
* Cache line size :64 B

**Για το hmmer:**
* L1 icache size :32 kB
* L1 icache associativity : 2-way
* L1 dcache size :32 kB
* L1 dcache associativity :4-way
* L2 cache size :1 MB
* L2 cache associativity :8-way
* Cache line size :64 B

**Για το sjeng:**
* L1 icache size :32 kB
* L1 icache associativity : 2-way
* L1 dcache size :32 kB
* L1 dcache associativity :4-way
* L2 cache size :1 MB
* L2 cache associativity :8-way
* Cache line size :64 B

**Για το libm:**
* L1 icache size :32 kB
* L1 icache associativity : 2-way
* L1 dcache size :32 kB
* L1 dcache associativity :4-way
* L2 cache size :1 MB
* L2 cache associativity :8-way
* Cache line size :64 B

### Κριτική εργασίας
Σε αυτή την εργασία ξοδέψαμε πολύ χρόνο στην αναζήτηση πληροφοριών για τον τρόπο μοντελοποίησης της ισχύος από τον McPAT και αποκτήσαμε μια διαφορετική νοοτροπία σχετικά με την κατασκευή επεξεργαστών, σκεπτόμενοι περισσότερο την κατανάλωση ενέργειας και τη σχέση ενέργειας απόδοσης παρά τη στείρα βελτιστοποίηση της απόδοσης. Η διαδικασία της αυτοματοποίησης των benchmark μας προέτρεψε να μάθουμε να γράφουμε και να τροποποιούμε python scripts για να μαζέψουμε δεδομένα από αρχεία, γνώση που θα μας φανεί ιδιαίτερα χρήσιμη και επαγγελματικά. Συνολικά το εργαστήριο αν και εξαιρετικά ενδιαφέρον ήταν δύσκολο στην εκπόνηση και "μπέρδευε" τον φοιτητή καθώς παρά την κατηγοριοποίηση του ως εργαστήριο ήταν περισσότερο μια μεγάλη εργασία εξαμήνου καθώς όλη η δουλειά γινόταν από πρίν στο σπίτι καθώς το περίπλοκο και χρονοβόρο περιεχόμενο του εργαστηρίου δεν επέτρεπε την εκπόνηση στον περιορισμένο χρόνο εκεί.Αυτό βέβαια σήμαινε ότι κατά τη διάρκεια του εργαστηρίου η ουσιαστική αλληλεπίδραση με τον διδάσκοντα για απορίες, διευκρινίσεις, βοήθεια ήταν περιορισμένη και η ώρα του εργαστηρίου ήταν περισσότερο απλώς ώρα εξέτασης και όχι δουλειάς.Βέβαια στο πλαίσιο του εργαστήριου μάθαμε πάρα πολλά πράγματα που μας έφεραν σε επαφή με την πραγματική δουλειά ενός αρχιτέκτονα υπολογιστών και προσωπικά μας κίνησε το ενδιαφέρον να ασχοληθούμε περαιτέρω με την αρχιτεκτονική σαν αντικείμενο.

### Πηγές
* [Computer Architecture, a quantitative approach](http://uni-site.ir/khuelec/wp-content/uploads/Computer-Architecture-A-Quantitative-Approach.pdf)
* [McPAT 1.0: Technical Report by hp labs](https://www.hpl.hp.com/research/mcpat/McPATAlpha_TechRep.pdf?fbclid=IwAR0zv3nuD7p2wTiU9U2wRF5yaEZ0zJMP6-AfH7oPrVxNhNYCXypWnLx1E6E)
* [McPAT: An Integrated Power, Area, and Timing Modeling Framework for Multicore and Manycore Architectures](https://www.hpl.hp.com/research/mcpat/micro09.pdf?fbclid=IwAR2VZqXlQ9tCC8uJKNzaWl1TnndP-t7VMYtcVv-uSSKcHcCdf3IOefo-il8)
* [McPAT Github Project](https://github.com/HewlettPackard/mcpat)
* [McPAT lecture from the Univ. of Texas: School of Electrical and Computer Eng.](http://users.ece.utexas.edu/~ljohn/teaching/382m-15/lectures/lec16.pdf)
