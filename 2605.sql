select products.name, providers.name
from products inner join providers on providers.id = id_providers
where id_categories = 6
