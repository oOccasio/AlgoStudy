package chuchu.miniproject.repository.team;

import chuchu.miniproject.domain.Team;
import org.springframework.data.jpa.repository.JpaRepository;

public interface TeamRepository extends JpaRepository<Team, Long> {
}
