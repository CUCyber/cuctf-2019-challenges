FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -yq --no-install-recommends \
        apache2 \
        libapache2-mod-php7.2 \
    && a2enmod php7.2 \
    && a2enmod rewrite \
    && service apache2 restart \
    && rm -f /var/www/html/index.html

ENV APACHE_RUN_USER www-data
ENV APACHE_RUN_GROUP www-data
ENV APACHE_LOG_DIR /var/log/apache2
ENV APACHE_LOCK_DIR /var/lock/apache2
ENV APACHE_PID_FILE /var/run/apache2.pid

COPY --chown=www-data:www-data website /var/www/html/
COPY --chown=root:root comms /comms
COPY --chown=root:root run.sh /run.sh

RUN chmod +x /comms \
    && chmod +x /run.sh

EXPOSE 80
EXPOSE 1337

CMD ["/bin/bash", "/run.sh"]
