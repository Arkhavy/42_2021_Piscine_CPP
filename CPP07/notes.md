
int	max(int x, int y) {return (x >= y ? x : y);}
==
template<typename T>
T	max(T x, T y) {return (x >= y ? x : y);}

||

template<typename T>
T const&	max(T const& x, T const& y) {return (x >= y ? x : y);}

comment utiliser ce bordel ?
utilisation d'une fonction template : max<int>(a, b); || max<float>(c, d); || max<char>(e, f);
ça fonctionne comme les casts, vaut mieux faire seulement de l'explicite par souci de clarté
instanciation explicite, implicite fonctionnera aussi

Il est possible de faire des fonctions et donc des classes templates

template<typename T>
class	List
{
	private:
		T*		content;
		List<T>*	next;
	public:
		List<T>(T const& content) {}
		List<T>(List<T> const& list) {}
		~List<T>() {}
};

________________________

template<typename T, typename U> fonctionne aussi évidemment