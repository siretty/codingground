#ifndef CCLIB_TPL_HH
#define CCLIB_TPL_HH 1

namespace lib {
  using size_t = decltype( sizeof(int) );

  template< size_t ... Is > class t_sizes {
      template< typename Jt > struct t_rem_prefix { };
      template< size_t J, size_t ... Js > struct t_rem_prefix< t_sizes< J, Js ... > > {
        using type = t_sizes< Js ... >;
      };
      
      template< typename Jt > struct t_rem_suffix { };
      template< size_t J, size_t ... Js > struct t_rem_suffix< t_sizes< J, Js ... > > {
        using rest = t
        using type = t_sizes< Js ... >;
      };
      
      using this_t = t_sizes< Is ... >;
  
    public:
    template< size_t I > using add_prefix_t = t_sizes< I, Is ... >;
    using rem_prefix_t = typename t_rem_prefix< this_t >::type;
    template< size_t I > using add_suffix_t = t_sizes< Is ..., I >;
    using rem_suffix_t = typename t_rem_suffix< this_t >::type;
    
    static const size_t size = sizeof...( Is );
  };
  
  template< typename ... Ts > struct t_types {
    template< typename T > using add_prefix_t = t_types< T, Ts ... >;
    template< typename T > using add_suffix_t = t_types< Ts ..., T >;
    
    static const size_t size = sizeof...( Ts );
  };
}

#endif /* inc guard */